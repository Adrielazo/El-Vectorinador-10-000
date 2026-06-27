#include "mainwindow.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QMessageBox>
 
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Vectorinador 10000 - Qt");
    resize(820, 480);
 
    auto *central = new QWidget(this);
    auto *layoutPrincipal = new QHBoxLayout(central);
 
   
    auto *columnaLista = new QVBoxLayout();
    columnaLista->addWidget(new QLabel("<b>Vectores en memoria</b>"));
    listaWidget = new QListWidget();
    columnaLista->addWidget(listaWidget);
    layoutPrincipal->addLayout(columnaLista, 1);
 
    
    auto *tabs = new QTabWidget();
 
    canvas = new VectorCanvas();
    canvas->setVectores(&listaVectores);
    tabs->addTab(canvas, "Plano X-Y (2D)");
 
    vista3d = new Vista3D();
    vista3d->setVectores(&listaVectores);
    tabs->addTab(vista3d, "Vista 3D (OpenGL)");
 
    layoutPrincipal->addWidget(tabs, 2);
 
   
    auto *columnaDerecha = new QVBoxLayout();
 
    
    auto *grupoEdicion = new QGroupBox("Crear / Modificar vector");
    auto *formEdicion = new QFormLayout();
    spinX = new QDoubleSpinBox(); spinX->setRange(-99999, 99999);
    spinY = new QDoubleSpinBox(); spinY->setRange(-99999, 99999);
    spinZ = new QDoubleSpinBox(); spinZ->setRange(-99999, 99999);
    formEdicion->addRow("X:", spinX);
    formEdicion->addRow("Y:", spinY);
    formEdicion->addRow("Z:", spinZ);
 
    auto *filaBotonesEdicion = new QHBoxLayout();
    btnCrear = new QPushButton("Crear nuevo");
    btnModificar = new QPushButton("Modificar seleccionado");
    btnEliminar = new QPushButton("Eliminar seleccionado");
    filaBotonesEdicion->addWidget(btnCrear);
    filaBotonesEdicion->addWidget(btnModificar);
    filaBotonesEdicion->addWidget(btnEliminar);
 
    auto *layoutEdicion = new QVBoxLayout();
    layoutEdicion->addLayout(formEdicion);
    layoutEdicion->addLayout(filaBotonesEdicion);
    grupoEdicion->setLayout(layoutEdicion);
    columnaDerecha->addWidget(grupoEdicion);
 
  
    auto *grupoOperar = new QGroupBox("Operar con vectores");
    auto *formOperar = new QFormLayout();
 
    comboOperacion = new QComboBox();
    comboOperacion->addItem("Multiplicacion por escalar");
    comboOperacion->addItem("Suma");
    comboOperacion->addItem("Resta");
    comboOperacion->addItem("Producto punto");
    comboOperacion->addItem("Producto cruz");
    comboOperacion->addItem("Modulo");
    comboOperacion->addItem("Vector unitario");
    comboOperacion->addItem("Angulo entre dos vectores");
 
    comboVector1 = new QComboBox();
    comboVector2 = new QComboBox();
    spinEscalar = new QDoubleSpinBox(); spinEscalar->setRange(-99999, 99999);
 
    formOperar->addRow("Operacion:", comboOperacion);
    formOperar->addRow("Vector 1:", comboVector1);
    formOperar->addRow("Vector 2:", comboVector2);
    formOperar->addRow("Escalar:", spinEscalar);
 
    checkGuardarResultado = new QCheckBox("¿Desea guardar el vector resultante en la lista?");
    checkGuardarResultado->setChecked(true);
 
    btnCalcular = new QPushButton("Calcular");
    labelResultado = new QLabel("Resultado: -");
    labelResultado->setWordWrap(true);
 
    auto *layoutOperar = new QVBoxLayout();
    layoutOperar->addLayout(formOperar);
    layoutOperar->addWidget(checkGuardarResultado);
    layoutOperar->addWidget(btnCalcular);
    layoutOperar->addWidget(labelResultado);
    grupoOperar->setLayout(layoutOperar);
    columnaDerecha->addWidget(grupoOperar);
 
    columnaDerecha->addStretch();
    layoutPrincipal->addLayout(columnaDerecha, 1);
 
    setCentralWidget(central);
 
    
    connect(btnCrear, &QPushButton::clicked, this, &MainWindow::crearVector);
    connect(btnModificar, &QPushButton::clicked, this, &MainWindow::modificarVector);
    connect(btnEliminar, &QPushButton::clicked, this, &MainWindow::eliminarVector);
    connect(btnCalcular, &QPushButton::clicked, this, &MainWindow::calcularOperacion);
    connect(comboOperacion, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::operacionSeleccionada);
    connect(listaWidget, &QListWidget::currentRowChanged,
            this, &MainWindow::cargarSeleccionEnCampos);
 
    operacionSeleccionada(comboOperacion->currentIndex());
    refrescarLista();
}
 
void MainWindow::refrescarLista() {
    listaWidget->clear();
    for (size_t i = 0; i < listaVectores.size(); ++i) {
        const Vector &v = listaVectores[i];
        QString texto = QString("[%1] (%2, %3, %4)")
                .arg(i).arg(v.getX()).arg(v.getY()).arg(v.getZ());
        listaWidget->addItem(texto);
    }
    refrescarCombosVectores();
    canvas->update();
    vista3d->update();
}
 
void MainWindow::refrescarCombosVectores() {
    comboVector1->clear();
    comboVector2->clear();
    for (size_t i = 0; i < listaVectores.size(); ++i) {
        comboVector1->addItem(QString("Vector %1").arg(i));
        comboVector2->addItem(QString("Vector %1").arg(i));
    }
}
 
void MainWindow::cargarSeleccionEnCampos(int row) {
    canvas->setIndiceResaltado(row);
    vista3d->setIndiceResaltado(row);
    if (row < 0 || row >= static_cast<int>(listaVectores.size())) return;
    const Vector &v = listaVectores[row];
    spinX->setValue(v.getX());
    spinY->setValue(v.getY());
    spinZ->setValue(v.getZ());
}
 

void MainWindow::crearVector() {
    listaVectores.push_back(Vector(spinX->value(), spinY->value(), spinZ->value()));
    refrescarLista();
}
 

void MainWindow::modificarVector() {
    int row = listaWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Aviso", "Selecciona un vector de la lista primero.");
        return;
    }
    listaVectores[row].modificar_vector(spinX->value(), spinY->value(), spinZ->value());
    refrescarLista();
}
 

void MainWindow::eliminarVector() {
    int row = listaWidget->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Aviso", "Selecciona un vector de la lista primero.");
        return;
    }
    listaVectores.erase(listaVectores.begin() + row);
    refrescarLista();
}
 

void MainWindow::operacionSeleccionada(int index) {
    bool necesitaEscalar = (index == 0);                 
    bool necesitaDosVectores = (index == 1 || index == 2 || index == 3 ||
                                 index == 4 || index == 7); 
    spinEscalar->setVisible(necesitaEscalar);
    comboVector2->setVisible(necesitaDosVectores);
}
 
void MainWindow::calcularOperacion() {
    if (listaVectores.empty()) {
        labelResultado->setText("Resultado: no hay vectores cargados.");
        return;
    }
    int i1 = comboVector1->currentIndex();
    int i2 = comboVector2->currentIndex();
    if (i1 < 0 || i1 >= static_cast<int>(listaVectores.size())) {
        labelResultado->setText("Resultado: indice de vector 1 invalido.");
        return;
    }
 
    const Vector &v1 = listaVectores[i1];
    int op = comboOperacion->currentIndex();
 
    switch (op) {
        case 0: { 
            Vector r = v1.mult_escalar(spinEscalar->value());
            QString texto = QString("Resultado: (%1, %2, %3)").arg(r.getX()).arg(r.getY()).arg(r.getZ());
            if (checkGuardarResultado->isChecked()) {
                listaVectores.push_back(r);
                refrescarLista();
                texto += " — agregado a la lista";
            }
            labelResultado->setText(texto);
            break;
        }
        case 1: case 2: case 3: case 4: case 7: { 
            if (i2 < 0 || i2 >= static_cast<int>(listaVectores.size())) {
                labelResultado->setText("Resultado: indice de vector 2 invalido.");
                return;
            }
            const Vector &v2 = listaVectores[i2];
            if (op == 1) {
                Vector r = v1 + v2;
                QString texto = QString("Suma: (%1, %2, %3)").arg(r.getX()).arg(r.getY()).arg(r.getZ());
                if (checkGuardarResultado->isChecked()) {
                    listaVectores.push_back(r);
                    refrescarLista();
                    texto += " — agregado a la lista";
                }
                labelResultado->setText(texto);
            } else if (op == 2) {
                Vector r = v1 - v2;
                QString texto = QString("Resta: (%1, %2, %3)").arg(r.getX()).arg(r.getY()).arg(r.getZ());
                if (checkGuardarResultado->isChecked()) {
                    listaVectores.push_back(r);
                    refrescarLista();
                    texto += " — agregado a la lista";
                }
                labelResultado->setText(texto);
            } else if (op == 3) {
                float r = v1.productopunto(v2);
                labelResultado->setText(QString("Producto punto: %1").arg(r));
            } else if (op == 4) {
                Vector r = v1.productocruz(v2);
                QString texto = QString("Producto cruz: (%1, %2, %3)").arg(r.getX()).arg(r.getY()).arg(r.getZ());
                if (checkGuardarResultado->isChecked()) {
                    listaVectores.push_back(r);
                    refrescarLista();
                    texto += " — agregado a la lista";
                }
                labelResultado->setText(texto);
            } else if (op == 7) {
                float ang = v1.angulo_entre(v2);
                labelResultado->setText(QString("Angulo entre vectores: %1°").arg(ang));
            }
            break;
        }
        case 5: { 
            labelResultado->setText(QString("Modulo: %1").arg(v1.modulo()));
            break;
        }
        case 6: { 
            Vector r = v1.unitario();
            labelResultado->setText(QString("Vector unitario: (%1, %2, %3)")
                .arg(r.getX()).arg(r.getY()).arg(r.getZ()));
            break;
        }
        default:
            labelResultado->setText("Resultado: operacion no implementada.");
    }
}
 
