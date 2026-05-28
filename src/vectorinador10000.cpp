#include "vectorinador10000.hpp"

//Se implementan funciones:

void nuevo_vector(std::vector<std::vector<float>>& lista_vec, int& cantidad_vec) {
    if (cantidad_vec < lista_vec.size()) {
        std::vector<float> vec_temp = {0, 0, 0};
        std::cout << "Ingrese componente en X: ";
        std::cin >> vec_temp[0];
        std::cout << "Ingrese componente en Y: ";
        std::cin >> vec_temp[1];
        std::cout << "Ingrese componente en Z: ";
        std::cin >> vec_temp[2];
        lista_vec.push_back(vec_temp);
        cantidad_vec++;
        std::cout << "Vector agregado exitosamente." << std::endl;
        return;
    }
    else {
        std::cout << "No se pueden agregar más vectores. Capacidad máxima alcanzada." << std::endl;
        return;
    }
}

void modificar_vector(std::vector<std::vector<float>>& lista_vec, int cantidad_vec, int indice) {
    if (indice < cantidad_vec && indice >=0) {
        std::vector<float> vec_temp = {0,0,0};
        std::cout << "Ingrese nueva componente en X: ";
        std::cin >> vec_temp[0];
        std::cout << "Ingrese nueva componente en Y: ";
        std::cin >> vec_temp[1];
        std::cout << "Ingrese nueva componente en Z: ";
        std::cin >> vec_temp[2];
        lista_vec[indice] = vec_temp;
        std::cout << "Vector modificado exitosamente." << std::endl;
    }
    else {
        std::cout << "Índice no válido. No se puede modificar el vector." << std::endl;
    }  
}

void mostrar_vectores(std::vector<std::vector<float>>& lista_vec, int cantidad_vec) {
    if (cantidad_vec >0) {
        std::cout << "------VECTORES ALMACENADOS------" << std::endl;
        for (int i = 0; i < cantidad_vec; i++) {
            std::cout << i+1 << ".- {" << lista_vec[i][0] << " , " << lista_vec[i][1] << " , " << lista_vec[i][2] << "}" << std::endl;

        }
    
    }
    else {
        std::cout << "No hay vectores almacenados." << std::endl;
    }
}

void eliminar_vector(std::vector<std::vector<float>>& lista_vec, int& cantidad_vec, int indice) {
    if (indice < cantidad_vec && indice >=0) {
        lista_vec.erase(lista_vec.begin() + indice);
        cantidad_vec--;
        std::cout << "Vector eliminado exitosamente." << std::endl;
    }
    else {
        std::cout << "Índice no válido. No se puede eliminar el vector." << std::endl;
    }
}
