#ifndef VECTORCANVAS_H
#define VECTORCANVAS_H

#include <QWidget>
#include <vector>
#include "vectorinador10000.hpp"

class VectorCanvas : public QWidget {
    Q_OBJECT

public:
    explicit VectorCanvas(QWidget *parent = nullptr);

    
    void setVectores(const std::vector<Vector> *vectores);
    void setIndiceResaltado(int index); 
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    const std::vector<Vector> *listaVectores = nullptr;
    int indiceResaltado = -1;

    double escala = 20.0; 

    QPointF mundoAPantalla(double x, double z, const QPointF &origenPantalla) const;
    void dibujarEjes(class QPainter &painter, const QPointF &origenPantalla);
    void dibujarFlecha(class QPainter &painter, const QPointF &desde, const QPointF &hasta, const QColor &color);
    double calcularEscalaAutomatica() const;
};

#endif 
