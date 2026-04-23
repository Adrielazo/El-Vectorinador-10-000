#ifndef VECTORINADOR_H
#define VECTORINADOR_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float x;
	float y;
} Vector;//corregi el id porque no es necesario, dentro del archivo de funciones hay que definir los valores

Vector suma_vector(Vector a, Vector b);
Vector resta_vector(Vector a, Vector b);
float producto_punto(Vector a, Vector b);
float modulo_vector(Vector v);
void imprimir_v(Vector v,const char*nombre); //Se define el vector "v", con un punto se puede ingresar a su valor (v.x por ejemplo)
// el const char*nombre es un puntero con constante, traduce la funcion para que la podamos ver en la consola PERO no la modifica

#endif
