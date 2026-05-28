#include "vectorinador20000.hpp"

int main() {
    std::cout << "Bienvenido!" << std::endl;
    int opcion;
    while (true) {
        std::cout << "¿Qué te gustaría hacer?" << std::endl;
        std::cout << "1. Agregar un nuevo vector" << std::endl;
        std::cout << "2. Modificar un vector existente" << std::endl;
        std::cout << "3. Mostrar todos los vectores almacenados" << std::endl;
        std::cout << "4. Eliminar un vector" << std::endl;
        std::cout << "5. Operar vectores" << std:: endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese el número de la opción deseada: ";
        std::cin >> opcion;
        std::cout << std::endl;

        switch (opcion) {
            case 1: {
                nuevo_vector(lista_vec, cantidad_vec);
                break;
            }
            case 2: {
                int indice_mod;
                std::cout << "Ingrese el número del vector a modificar: ";
                std::cin >> indice_mod;
                modificar_vector(lista_vec, cantidad_vec, indice_mod-1);
                break;
            }
            case 3: {
                mostrar_vectores(lista_vec, cantidad_vec);
                break;
            }
            case 4: {
                int indice_elim;
                std::cout << "Ingrese el número del vector a eliminar: ";
                std::cin >> indice_elim;
                eliminar_vector(lista_vec, cantidad_vec, indice_elim-1);
                break;
            }
            case 5: {
                std::cout << "¿Qué operación deseas realizar?" << std::endl;
                std::cout << "1. Suma de vectores" << std::endl;
                std::cout << "2. Resta de vectores" << std::endl;
                std::cout << "3. Producto punto" << std::endl;
                std::cout << "4. Producto cruz" << std::endl;
                std::cout << "5. Módulo de un vector" << std::endl;
                std::cout << "6. Volver al menú principal" << std::endl;
                int operacion;
                std::cout << "Ingrese el número de la operación deseada: ";
                std::cin >> operacion;
                switch (operacion) {
                    case 1: {
                        int indice_a, indice_b;
                        mostrar_vectores(lista_vec, cantidad_vec);
                        std::cout << "Ingrese el número del primer vector: ";
                        std::cin >> indice_a;
                        std::cout << "Ingrese el número del segundo vector: ";
                        std::cin >> indice_b;
                        std::vector<float> resultado_suma = suma_v(indice_a-1, indice_b-1, lista_vec);
                        std::cout << "Resultado de la suma: {" << resultado_suma[0] << " , " << resultado_suma[1] << " , " << resultado_suma[2] << "}" << std::endl;
                        break;
                    }
                    case 2: {
                        int indice_a, indice_b;
                        mostrar_vectores(lista_vec, cantidad_vec);
                        std::cout << "Ingrese el número del primer vector: ";
                        std::cin >> indice_a;
                        std::cout << "Ingrese el número del segundo vector: ";
                        std::cin >> indice_b;
                        std::vector<float> resultado_resta = resta_v(indice_a-1, indice_b-1, lista_vec);
                        std::cout << "Resultado de la resta: {" << resultado_resta[0] << " , " << resultado_resta[1] << " , " << resultado_resta[2] << "}" << std::endl;
                        break;
                    }
                    case 3: {
                        int indice_a, indice_b;
                        mostrar_vectores(lista_vec, cantidad_vec);
                        std::cout << "Ingrese el número del primer vector: ";
                        std::cin >> indice_a;
                        std::cout << "Ingrese el número del segundo vector: ";
                        std::cin >> indice_b;
                        float resultado_producto_punto = producto_punto(indice_a-1, indice_b-1, lista_vec);
                        std::cout << "Resultado del producto punto: " << resultado_producto_punto << std::endl;
                        break;
                    }
                    case 4: {
                        int indice_a, indice_b;
                        mostrar_vectores(lista_vec, cantidad_vec);
                        std::cout << "Ingrese el número del primer vector: ";
                        std::cin >> indice_a;
                        std::cout << "Ingrese el número del segundo vector: ";
                        std::cin >> indice_b;
                        std::vector<float> resultado_producto_cruz = producto_cruz(indice_a-1, indice_b-1, lista_vec);
                        std::cout << "Resultado del producto cruz: {" << resultado_producto_cruz[0] << " , " << resultado_producto_cruz[1] << " , " << resultado_producto_cruz[2] << "}" << std::endl;
                        break;
                    }
                    case 5: {
                        int indice;
                        mostrar_vectores(lista_vec, cantidad_vec);
                        std::cout << "Ingrese el número del vector: ";
                        std::cin >> indice;
                        float resultado_modulo = modulo_v(indice-1, lista_vec);
                        std::cout << "Resultado del módulo: " << resultado_modulo << std::endl;
                        break;
                    }
                    case 6: {
                        std::cout << "Volviendo..." << std::endl;
                        break;
                    
                    }
                break;
            
            }
            case 6: {
                std::cout << "¡Hasta luego!" << std::endl;
                return 0;
            }
        }   
     }
}
}
