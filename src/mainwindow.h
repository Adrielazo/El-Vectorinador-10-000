#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QTabWidget>
#include <QCheckBox>
#include <vector>
#include "vectorinador10000.hpp"
#include "vectorcanvas.h"
#include "vista3d.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    // Cada uno reemplaza un "case" del switch original
    void crearVector();
    void modificarVector();
    void eliminarVector();
    void calcularOperacion();
    void operacionSeleccionada(int index);
    void cargarSeleccionEnCampos(int row); // al hacer click en la lista, carga X/Y/Z en los spinbox

private:
    std::vector<Vector> listaVectores;

    // Lista / panel izquierdo
    QListWidget *listaWidget;

    // Plano cartesiano X-Z
    VectorCanvas *canvas;

    // Vista 3D con OpenGL
    Vista3D *vista3d;

    // Panel "crear / modificar"
    QDoubleSpinBox *spinX, *spinY, *spinZ;
    QPushButton *btnCrear;
    QPushButton *btnModificar;
    QPushButton *btnEliminar;

    // Panel "operar"
    QComboBox *comboOperacion;
    QComboBox *comboVector1;
    QComboBox *comboVector2;     // se oculta si la operacion no necesita 2 vectores
    QDoubleSpinBox *spinEscalar; // se muestra solo para mult. por escalar
    QCheckBox *checkGuardarResultado;
    QPushButton *btnCalcular;
    QLabel *labelResultado;

    void refrescarLista();      // equivalente a mostrarVector()
    void refrescarCombosVectores();
};
#endif // MAINWINDOW_H
