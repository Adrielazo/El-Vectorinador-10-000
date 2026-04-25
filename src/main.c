#include "vectorinador.h"

int main(){
	Vector *v1=(Vector*)malloc(sizeof(Vector));
	Vector *v2=(Vector*)malloc(sizeof(Vector));
	int opcion;

	printf("Ingrese datos del primer vector: ");
	printf("\nValor en x: ");
	scanf("%f", &v1->x);
	printf("\nValor en y: ");
	scanf("%f", &v1->y);
	printf("\nAhora datos del segundo vector: ");
	printf("\nValor en x: ");
	scanf("%f", &v2->x);
	printf("\nValor en y: ");
	scanf("%f", &v2->y);
	
	do {
		printf("\n===MENÚ===\n¿Qué te gustaría hacer?\n");
		printf("\n\t1.- Sumar vectores.");
		printf("\n\t2.- Restar vectores.");
		printf("\n\t3.- Producto punto.");
		printf("\n\t4.- Calcular módulo.");
		printf("\n\t5.- Modificar vector.");
		printf("\n\t0.- Salir.");
		printf("\n\tIngresar opción: ");
		scanf("%d", &opcion);
		getchar();
	
		switch (opcion){

			case 1:
				Vector s = suma_vector(v1,v2);
				printf("\nSuma: (%.2f,%.2f)\n",s.x, s.y);
				break;
			case 2:
				Vector r = resta_vector(v1,v2);
				printf("\nResta: (%.2f,%.2f)\n",r.x, r.y);
				break;
			case 3:
				float pp = producto_punto(v1,v2);
				printf("\nProducto punto: %2f\n", pp);
				break;
			case 4:
				float mod1= modulo_vector(v1);
				printf("\nMódulo vector 1: %2f\n", mod1);
				float mod2= modulo_vector(v2);
				printf("\nMódulo vector 2: %2f\n", mod2);
				break;
			case 5:
				printf("\nWIP\n");
				break;
			case 0:
				printf("\nAdiós.\n");
				break;
			default:
				printf("\nOpción inválida.\n");
				break;

		}	
	}while (opcion != 0);

	free(v1);
	free(v2);
	return 0;
}
