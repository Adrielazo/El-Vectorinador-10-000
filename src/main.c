#include "vectorinador.h"
int main(){
	Vector *v1=(Vector*)malloc(sizeof(Vector));
	Vector *v2=(Vector*)malloc(sizeof(Vector));
	int opcion;

	printf("Ingrese datos del primer vector: \n");
	printf("Valor en x: ");
	scanf("%f", &v1->x);
	printf("\nValor en y: ");
	scanf("%f", &v1->y);
	printf("\nAhora datos del segundo vector: ");
	printf("\nValor en x: ");
	scanf("%f", &v2->x);
	printf("\nValor en y: ");
	scanf("%f", &v2->y);
	
	printf("\n===MENÚ===\n¿Qué te gustaría hacer?");
	printf("\n1.- Sumar vectores.");
	printf("\n2.- Restar vectores.");
	printf("\n3.- Producto punto.");
	printf("\n4.- Calcular módulo.");
	printf("\n5.- Modificar vector.");
	printf("\n0.- Salir.");
	scanf("%d",opcion);
	switch opcion{
		case 1:
		Vector s = suma_vector(v1,v2);
		printf("\nSuma: (%.2f,%.2f)",s.x, s.y);
		case 2:
		Vector r = resta_vector(v1,v2);
		printf("\nResta: (%.2f,%.2f)",r.x, r.y);
		case 3:
		float pp = producto_punto(v1,v2);
		printf("\nProducto punto: %2f", pp);
		case 4:
		float mod1= modulo_vector(v1);
		printf("\nMódulo vector 1: %2f \n", mod1);
		float mod2= modulo_vector(v2);
		printf("\nMódulo vector 2: %2f \n", mod2);
		case 5:
		printf("WIP");
		default:
		printf("opción inválida.");
	}while (opcion != 0);


	free(v1);
	free(v2);
	return 0;
}
