#ifndef VISTA3D_H
#define VISTA3D_H

#include <QOpenGLWidget>
#include <QPoint>
#include <vector>
#include "vectorinador10000.hpp"

class Vista3D : public QOpenGLWidget {
    Q_OBJECT

public:
    explicit Vista3D(QWidget *parent = nullptr);

    void setVectores(const std::vector<Vector> *vectores);
    void setIndiceResaltado(int index);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    const std::vector<Vector> *listaVectores = nullptr;
    int indiceResaltado = -1;

   
    float anguloX = 25.0f;  
    float anguloY = -35.0f;  
    float zoom = 8.0f;       
    QPoint ultimaPosMouse;

    void dibujarEjes();
    void dibujarGrilla();
    void dibujarFlecha3D(float x, float y, float z, float r, float g, float b);
};

#endif 
