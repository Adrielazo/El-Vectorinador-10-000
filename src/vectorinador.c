#include "vectorinador.h"

Vector suma_vector(Vector a, Vector b){
	Vector resultado = {a.x + b.x, a.y + b.y};
	return resultado;
}//¿Por que no poner los printf acá? Más que nada por optimización, lo que estamos buscando en este archivo es dejar definidas las
//funciones matemáticas del cálculo de vectores, meter print puede ser un gasto de líneas y memoria innecesarios en este
//archivo, por lo que se lo dejamos al archivo main, el cual se encargará de mostrar todos los print en la consola para que
//el usuario pueda interactuar


Vector resta_vector(Vector a, Vector b){
	Vector resultado = {a.x - b.x, a.y - b.y};
	return resultado;
}

float producto_punto(Vector a, Vector b){
	return float {a.x*b.x + a.y*b.y}; 
}

float modulo_vector(Vector v){
	return float{sqrt((v.x*v.x)+(v.y*v.y))};
}
