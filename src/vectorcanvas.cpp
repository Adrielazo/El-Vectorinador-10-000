#include "vectorcanvas.h"
#include <QPainter>
#include <QPainterPath>
#include <cmath>
#include <algorithm>

VectorCanvas::VectorCanvas(QWidget *parent) : QWidget(parent) {
    setMinimumSize(400, 400);
    setAutoFillBackground(true);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setPalette(pal);
}

void VectorCanvas::setVectores(const std::vector<Vector> *vectores) {
    listaVectores = vectores;
    update(); 
}

void VectorCanvas::setIndiceResaltado(int index) {
    indiceResaltado = index;
    update();
}


QPointF VectorCanvas::mundoAPantalla(double x, double y, const QPointF &origenPantalla) const {
    return QPointF(origenPantalla.x() + x * escala,
                    origenPantalla.y() - y * escala);
}

double VectorCanvas::calcularEscalaAutomatica() const {
    if (!listaVectores || listaVectores->empty()) return 20.0;

    double maxComponente = 1.0; 
    for (const auto &v : *listaVectores) {
        maxComponente = std::max({maxComponente,
                                   (double)std::fabs(v.getX()),
                                   (double)std::fabs(v.getY())});
    }

   
    double mitadLadoMenor = std::min(width(), height()) / 2.0;
    double escalaCalculada = (mitadLadoMenor * 0.8) / maxComponente;
    return std::max(5.0, std::min(escalaCalculada, 80.0)); 
}

void VectorCanvas::dibujarFlecha(QPainter &painter, const QPointF &desde, const QPointF &hasta, const QColor &color) {
    painter.setPen(QPen(color, 2));
    painter.setBrush(color);
    painter.drawLine(desde, hasta);

    
    double angulo = std::atan2(hasta.y() - desde.y(), hasta.x() - desde.x());
    double largoPunta = 10.0;
    double anguloPunta = M_PI / 7.0;

    QPointF p1 = hasta - QPointF(std::cos(angulo - anguloPunta), std::sin(angulo - anguloPunta)) * largoPunta;
    QPointF p2 = hasta - QPointF(std::cos(angulo + anguloPunta), std::sin(angulo + anguloPunta)) * largoPunta;

    QPainterPath punta;
    punta.moveTo(hasta);
    punta.lineTo(p1);
    punta.lineTo(p2);
    punta.closeSubpath();
    painter.drawPath(punta);
}

void VectorCanvas::dibujarEjes(QPainter &painter, const QPointF &origenPantalla) {
    painter.setPen(QPen(QColor(180, 180, 180), 1));

    
    int pasos = (int)(std::max(width(), height()) / (2 * escala)) + 2;
    for (int i = -pasos; i <= pasos; ++i) {
        if (i == 0) continue;
        
        double px = origenPantalla.x() + i * escala;
        painter.drawLine(QPointF(px, 0), QPointF(px, height()));
       
        double py = origenPantalla.y() - i * escala;
        painter.drawLine(QPointF(0, py), QPointF(width(), py));
    }

    
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(QPointF(0, origenPantalla.y()), QPointF(width(), origenPantalla.y())); // eje X
    painter.drawLine(QPointF(origenPantalla.x(), 0), QPointF(origenPantalla.x(), height())); // eje Y

    painter.drawText(QPointF(width() - 20, origenPantalla.y() - 8), "X");
    painter.drawText(QPointF(origenPantalla.x() + 8, 15), "Y");
    painter.drawText(QPointF(origenPantalla.x() + 6, origenPantalla.y() + 18), "0");

   
    painter.setPen(QPen(Qt::darkGray, 1));
    for (int i = -pasos; i <= pasos; ++i) {
        if (i == 0) continue;
        double px = origenPantalla.x() + i * escala;
        if (px > 0 && px < width())
            painter.drawText(QPointF(px - 5, origenPantalla.y() + 14), QString::number(i));
        double py = origenPantalla.y() - i * escala;
        if (py > 0 && py < height())
            painter.drawText(QPointF(origenPantalla.x() + 4, py + 4), QString::number(i));
    }
}

void VectorCanvas::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    escala = calcularEscalaAutomatica();
    QPointF origenPantalla(width() / 2.0, height() / 2.0);

    dibujarEjes(painter, origenPantalla);

    if (!listaVectores) return;

    
    static const QColor colores[] = {
        QColor(220, 50, 50), QColor(50, 120, 220), QColor(40, 160, 70),
        QColor(200, 140, 0), QColor(150, 60, 200), QColor(0, 150, 150)
    };

    for (size_t i = 0; i < listaVectores->size(); ++i) {
        const Vector &v = (*listaVectores)[i];
        QPointF destino = mundoAPantalla(v.getX(), v.getY(), origenPantalla);

        bool resaltado = ((int)i == indiceResaltado);
        QColor color = colores[i % 6];
        if (resaltado) color = Qt::magenta;

        dibujarFlecha(painter, origenPantalla, destino, color);

        painter.setPen(resaltado ? Qt::magenta : color);
        painter.drawText(destino + QPointF(6, -6), QString("V%1").arg(i));
    }
}
