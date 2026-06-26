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
    
    void crearVector();
    void modificarVector();
    void eliminarVector();
    void calcularOperacion();
    void operacionSeleccionada(int index);
    void cargarSeleccionEnCampos(int row); 

private:
    std::vector<Vector> listaVectores;

    QListWidget *listaWidget;

    VectorCanvas *canvas;
    Vista3D *vista3d;

    
    QDoubleSpinBox *spinX, *spinY, *spinZ;
    QPushButton *btnCrear;
    QPushButton *btnModificar;
    QPushButton *btnEliminar;
    QComboBox *comboOperacion;
    QComboBox *comboVector1;
    QComboBox *comboVector2; 
    QDoubleSpinBox *spinEscalar; 
    QCheckBox *checkGuardarResultado;
    QPushButton *btnCalcular;
    QLabel *labelResultado;

    void refrescarLista();      // equivalente a mostrarVector()
    void refrescarCombosVectores();
};
#endif 
