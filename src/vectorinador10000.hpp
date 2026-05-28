#include <iostream>
#include <vector>


//Se definen variables:
std::vector<std::vector<float>> lista_vec (10);
int cantidad_vec = 0;

//Se definen funciones:

void nuevo_vector(std::vector<std::vector<float>>& lista_vec, int& cantidad_vec);

void modificar_vector(std::vector<std::vector<float>>& lista_vec, int cantidad_vec, int indice);

void mostrar_vectores(std::vector<std::vector<float>>& lista_vec, int cantidad_vec);

void eliminar_vector(std::vector<std::vector<float>>& lista_vec, int& cantidad_vec, int indice);

//Se definen operaciones:
std::vector<float> suma_v(int indice_a, int indice_b, std::vector<std::vector<float>>& lista_vec);
std::vector<float> resta_v(int indice_a, int indice_b, std::vector<std::vector<float>>& lista_vec);
float producto_punto(int indice_a, int indice_b, std::vector<std::vector<float>>& lista_vec);
std::vector<float> producto_cruz(int indice_a, int indice_b, std::vector<std::vector<float>>& lista_vec);
float modulo_v(int indice, std::vector<std::vector<float>>& lista_vec);
