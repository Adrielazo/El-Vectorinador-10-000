#include "vectorinador.h"
int main(){
	Vector *v1=(Vector*)malloc(sizeof(Vector));
	Vector *v2=(Vector*)malloc(sizeof(Vector));

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
	
	Vector s = suma_vector(v1,v2);
	printf("\nSuma: (%.2f,%.2f)",s.x, s.y);

	Vector r = resta_vector(v1,v2);
	printf("\nResta: (%.2f,%.2f)",r.x, r.y);

	float pp = producto_punto(v1,v2);
	printf("\nProducto punto: %2f", pp);

	float mod= modulo_vector(v1);
	printf("\nMódulo: %2f \n", mod);


	free(v1);
	free(v2);
	return 0;
}
