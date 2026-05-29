#include "vectorinador10000.hpp"

void mostrarVector(const std::vector<Vector>& lista){
    std::cout << "\n---Vectores en memoria---\n";
    if (lista.empty()){
        std::cout << "No hay vectores en memoria.";
        return;
    }
    for (size_t i = 0; i < lista.size(); ++i) {
        std::cout<<"Indice["<<i<<"]: ";
        lista[i].imprimir_vector();
    }
}

int main (){
    std::vector<Vector> listaVectores;
    int opcion = 0;
    int operacion = 0;
    do{
        std::cout<<"\n---Menu de opciones---\n";
        std::cout<<"1. Crear un nuevo vector\n";
        std::cout<<"2. Ver todos los vectores\n";
        std::cout<<"3. Modificar un vector existente\n";
        std::cout<<"4. Operar con vectores\n";
        std::cout<<"5. Salir\n";
        std::cout<<"6. Eliminar un vector\n";
        std::cout<<"Seleccione una opcion: ";
        std::cin>>opcion;

        switch (opcion){
            case 1: {
                float x, y, z;
                std::cout<<"Ingrese las componentes del vector (X Y Z):\n ";
                std::cout<<"Ingrese la componente en X: "; std::cin>>x;
                std::cout<<"Ingrese la componente en Y: "; std::cin>>y;
                std::cout<<"Ingrese la componente en Z: "; std::cin>>z;
                listaVectores.push_back(Vector(x, y, z));
                std::cout<<"¡Vector creado exitosamente!.\n";
                break; 
                mostrarVector(listaVectores);
                break;  
            } 
            case 2: {
                mostrarVector(listaVectores);
            }
            case 3:{
                if (listaVectores.empty()){
                    std::cout<<"No hay vectores para modificar.\n";
                    break;
                }
                size_t indice;
                std::cout<<"Ingrese el indice del vector a modificar: ";
                std::cin>>indice;

                if (indice < listaVectores.size()){
                    float X, Y, Z;
                    std::cout << "Ingrese los nuevos componentes X,Y,Z (Separados por espacio)";
                    std::cin >> X >> Y >> Z;
                    listaVectores[indice].modificar_vector(X, Y, Z);
                    std::cout<<"¡Vector modificado exitosamente!.\n";   
                } else{
                    std::cout<<"Indice invalido. No se modifico ningun vector.\n";
                }
                break;
            }
            
            case 4:{
                std::cout << "¿Que operacion deseas realizar?\n";
                std::cout << "0. Multiplicacion por escalar\n";
                std::cout << "1. Suma\n" ;
                std::cout << "2. Resta\n" ;
                std::cout << "3. Producto punto\n" ;
                std::cout << "4. Producto cruz\n" ;
                std::cout << "5. Modulo de un vector\n" ;
                std::cout << "6. Volver al menu principal\n" ;
                std::cout << "Ingrese el numero de la operacion deseada: ";
                std::cin >> operacion;

                switch (operacion) {
                    case 0: {
                        if (listaVectores.empty()){
                            std::cout<<"No hay vectores para multiplicar por un escalar.\n";
                            break;
                        }
                        mostrarVector(listaVectores);
                        size_t indice;
                        float escalar;
                        std::cout<<"Ingrese el indice del vector a multiplicar: "; std::cin>>indice;
                        std::cout<<"Ingrese el valor del escalar: "; std::cin>>escalar;

                        if(indice<listaVectores.size()){
                            Vector resultado = listaVectores[indice].mult_escalar(escalar);
                            std::cout<<"Resultado de la multiplicacion por escalar: ";
                            resultado.imprimir_vector();
                        } else{
                            std::cout<<"Indice invalido. No se realizo la multiplicacion por escalar.\n";
                        }
                        break;
                    }
                    case 1: {
                        if (listaVectores.size() < 1){
                            std::cout<<"Se necesita al menos un vector para realizar la suma";
                            break;
                        }
                        mostrarVector(listaVectores);
                        size_t indice1, indice2;
                        std::cout<<"Ingrese el indice del primer vector: "; std::cin>>indice1;
                        std::cout<<"Ingrese el indice del segundo vector: "; std::cin>>indice2;
                        if(indice1<listaVectores.size() && indice2<listaVectores.size()){
                            Vector resultado = listaVectores[indice1] + listaVectores[indice2];
                            std::cout<<"Resultado de la suma: ";
                            resultado.imprimir_vector();
                        } else{
                            std::cout<<"Uno o ambos indices son invalidos. No se realizo la suma.\n";
                        }
                        break;
                    
                    }
                    case 2:{
                        if (listaVectores.size() < 1){
                            std::cout<<"Se necesita al menos un vector para realizar la resta";
                            break;
                        }
                        mostrarVector(listaVectores);
                        size_t indice1, indice2;
                        std::cout<<"Ingrese el indice del primer vector: "; std::cin>>indice1;
                        std::cout<<"Ingrese el indice del segundo vector: "; std::cin>>indice2;

                        if(indice1<listaVectores.size() && indice2<listaVectores.size()){
                            Vector resultado = listaVectores[indice1] - listaVectores[indice2];
                            std::cout<<"Resultado de la resta: ";
                            resultado.imprimir_vector();
                        } else{
                            std::cout<<"Uno o ambos indices son invalidos. No se realizo la resta.\n";
                        }
                        break;
                    }
                    case 3:{
                        if (listaVectores.size() < 1){
                            std::cout<<"Se necesita al menos un vector para calcular el producto punto\n";
                            break;
                        }
                        mostrarVector(listaVectores);
                        size_t indice1, indice2;
                        std::cout<<"Ingrese el indice del primer vector: "; std::cin>>indice1;
                        std::cout<<"Ingrese el indice del segundo vector: "; std::cin>>indice2;
                        if(indice1<listaVectores.size() && indice2<listaVectores.size()){
                            float punto = listaVectores[indice1].productopunto(listaVectores[indice2]);
                            std::cout<<"Resultado del producto punto: "<<punto<<"\n";
                        } else{
                            std::cout<<"Uno o ambos indices son invalidos. No se realizo el calculo del producto punto.\n";
                        }
                        break;
                    }
                    case 4:{
                        if (listaVectores.size() < 2){
                            std::cout<<"Se necesitan al menos dos vectores para calcular el producto cruz";
                            break;
                        }
                        mostrarVector(listaVectores);
                        size_t indice1, indice2;
                        std::cout<<"Ingrese el indice del primer vector: "; std::cin>>indice1;
                        std::cout<<"Ingrese el indice del segundo vector: "; std::cin>>indice2;
                        if(indice1<listaVectores.size() && indice2<listaVectores.size()){
                            Vector resultado = listaVectores[indice1].productocruz(listaVectores[indice2]);
                            std::cout<<"Resultado del producto cruz: ";
                            resultado.imprimir_vector();
                        } else{
                            std::cout<<"Uno o ambos indices son invalidos. No se realizo el calculo del producto cruz.\n";
                        }
                        break;
                    }
                    case 5:{
                        if (listaVectores.empty()){
                            std::cout<<"\nError: No hay vectores almacenados.\n";
                            break;
                        }
                        mostrarVector(listaVectores);
                        size_t indice;
                        std::cout<<"Ingrese el indice del vector para calcular su modulo: "; std::cin>>indice;
                        if(indice<listaVectores.size()){
                            float modulo = listaVectores[indice].modulo();
                            std::cout<<"El modulo del vector es: "<<modulo<<"\n";
                        } else{
                            std::cout<<"Indice invalido.\n";
                        }
                        break;
                    }
                    case 6:{
                        std::cout<<"Volviendo...\n";
                        break;
                    }
                    default:{
                        std::cout<<"Opcion invalida. Por favor, seleccione una opcion del 1 al 6.\n";
                        break;
                    }   
            }
            }
            case 5:{
                std::cout<<"¡Hasta luego!\n";
                break;
            }
            case 6:{
                if (listaVectores.empty()){
                    std::cout<<"No hay vectores para eliminar.\n";
                    break;
                }
                mostrarVector(listaVectores);
                size_t indice;
                std::cout<<"Ingrese el indice del vector a eliminar: ";
                std::cin>>indice;

                if (indice < listaVectores.size()){
                    listaVectores.erase(listaVectores.begin() + indice);
                    std::cout<<"¡Vector eliminado exitosamente!.\n";   
                } else{
                    std::cout<<"Indice invalido. No se elimino ningun vector.\n";
                }
                break;
            }
            default:{
                std::cout<<"Opcion invalida. Por favor, seleccione una opcion del 1 al 6.\n";
                break;
             }
        
            
        }
    } while (opcion != 5); 
    return 0;
}   
 
