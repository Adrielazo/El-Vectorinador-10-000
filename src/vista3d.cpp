#include "vista3d.h"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <cmath>

#ifdef Q_OS_WIN
#include <windows.h>
#endif

#ifdef Q_OS_MAC
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

Vista3D::Vista3D(QWidget *parent) : QOpenGLWidget(parent) {
    setMinimumSize(400, 400);
}

void Vista3D::setVectores(const std::vector<Vector> *vectores) {
    listaVectores = vectores;
    update();
}

void Vista3D::setIndiceResaltado(int index) {
    indiceResaltado = index;
    update();
}

void Vista3D::initializeGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void Vista3D::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}


void Vista3D::dibujarFlecha3D(float x, float y, float z, float r, float g, float b) {
    glColor3f(r, g, b);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(x, y, z);
    glEnd();

    
    float largo = std::sqrt(x*x + y*y + z*z);
    if (largo < 0.0001f) return;
    float dx = x / largo, dy = y / largo, dz = z / largo;
    float tam = std::min(0.25f, largo * 0.15f);

    
    float px, py, pz;
    if (std::fabs(dy) < 0.99f) { px = -dz; py = 0; pz = dx; }
    else { px = 1; py = 0; pz = 0; }
    float pl = std::sqrt(px*px + py*py + pz*pz);
    px /= pl; py /= pl; pz /= pl;
    float qx = dy*pz - dz*py, qy = dz*px - dx*pz, qz = dx*py - dy*px;

    glBegin(GL_LINES);
    for (int i = 0; i < 6; ++i) {
        float ang = (float)i / 6.0f * 2.0f * M_PI;
        float ox = (px * std::cos(ang) + qx * std::sin(ang)) * tam;
        float oy = (py * std::cos(ang) + qy * std::sin(ang)) * tam;
        float oz = (pz * std::cos(ang) + qz * std::sin(ang)) * tam;
        glVertex3f(x, y, z);
        glVertex3f(x - dx*tam*1.5f + ox, y - dy*tam*1.5f + oy, z - dz*tam*1.5f + oz);
    }
    glEnd();
}

void Vista3D::dibujarEjes() {
    float L = 5.0f;
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        
        glColor3f(0.85f, 0.15f, 0.15f);
        glVertex3f(-L, 0, 0); glVertex3f(L, 0, 0);
        
        glColor3f(0.15f, 0.65f, 0.15f);
        glVertex3f(0, -L, 0); glVertex3f(0, L, 0);
        
        glColor3f(0.15f, 0.35f, 0.85f);
        glVertex3f(0, 0, -L); glVertex3f(0, 0, L);
    glEnd();
}

void Vista3D::dibujarGrilla() {
    glColor3f(0.85f, 0.85f, 0.85f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    int N = 10;
    for (int i = -N; i <= N; ++i) {
        glVertex3f((float)i, 0, -N); glVertex3f((float)i, 0, N);
        glVertex3f(-N, 0, (float)i); glVertex3f(N, 0, (float)i);
    }
    glEnd();
}

void Vista3D::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspecto = (float)width() / (float)std::max(1, height());
    gluPerspective(45.0, aspecto, 0.1, 200.0);

    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -zoom);
    glRotatef(anguloX, 1, 0, 0);
    glRotatef(anguloY, 0, 1, 0);

    dibujarGrilla();
    dibujarEjes();

    if (listaVectores) {
        static const float colores[6][3] = {
            {0.8f, 0.2f, 0.2f}, {0.2f, 0.4f, 0.8f}, {0.2f, 0.6f, 0.3f},
            {0.8f, 0.55f, 0.0f}, {0.55f, 0.2f, 0.75f}, {0.0f, 0.6f, 0.6f}
        };
        for (size_t i = 0; i < listaVectores->size(); ++i) {
            const Vector &v = (*listaVectores)[i];
            bool resaltado = ((int)i == indiceResaltado);
            float r = resaltado ? 1.0f : colores[i % 6][0];
            float g = resaltado ? 0.0f : colores[i % 6][1];
            float b = resaltado ? 1.0f : colores[i % 6][2];
            dibujarFlecha3D(v.getX(), v.getY(), v.getZ(), r, g, b);
        }
    }

    
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawText(10, 20, "Arrastra: rotar | Rueda: zoom");
    painter.setPen(QColor(217, 38, 38));
    painter.drawText(10, 40, "Eje X");
    painter.setPen(QColor(38, 166, 38));
    painter.drawText(10, 58, "Eje Y");
    painter.setPen(QColor(38, 89, 217));
    painter.drawText(10, 76, "Eje Z");
    painter.end();
}

void Vista3D::mousePressEvent(QMouseEvent *event) {
    ultimaPosMouse = event->pos();
}

void Vista3D::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        QPoint delta = event->pos() - ultimaPosMouse;
        anguloY += delta.x() * 0.5f;
        anguloX += delta.y() * 0.5f;
        ultimaPosMouse = event->pos();
        update();
    }
}

void Vista3D::wheelEvent(QWheelEvent *event) {
    float pasos = event->angleDelta().y() / 120.0f;
    zoom -= pasos * 0.6f;
    zoom = std::max(2.0f, std::min(zoom, 60.0f));
    update();
}
