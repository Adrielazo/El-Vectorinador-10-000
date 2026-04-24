# El-Vectorinador-10-000
### ¿Por qué? (problemática)
Existe una falta de herramientas interactivas que permitan visualizar las operaciones realizadas en el plano vectorial, lo que entorpece el aprendizaje de esta materia, que, al ser un concepto clave en el estudio de las ciencias básicas, es muy importante comprender y dominar.

### Objetivos generales.
Desarrollar un entorno claro en donde tanto alumnos como profesores puedan experimentar o comprobar los resultados de operaciones vectoriales, facilitando así la comprensión de este tema.

### Objetivos específicos.
- Definir funciones de operaciones de vectores en 2 dimensiones: suma, resta, módulo y producto punto.
- Crear menú interactivo para el prototipo.
### Integrantes/Roles
- **Damián Cabrera (Adrielazo)**: Control de calidad (tester) y administración de repositorio
- **Vicente Manríquez (Pilsenshot)**: Programación de lógica.
- **Martín Urrutia (kourzed):** Documentación y gestión.
- **Lukas Valenzuela (Lukakas16):** Programación de lógica.

### Funcionalidades implementadas y pruebas realizadas.

#### Funcionalidades
- Menú sencillo e interactivo donde se pueden escojer las diferentes operaciones vectoriales que ofrece el programa.
- Operaciones vectoriales de 2 vectores de 2 dimensiones:
  1. **Suma y resta**:
	  * Estas dos funciones trabajan sumando y/o la componente x del primer vector (V1) y la del segundo vector (V2), lo mismo para la componente y, para luego mostrar en pantalla este resultado.
  2. **Producto punto**:
	  * Multiplica la componente x de V1 y la de V2, así mismo para la componente y de ambos y luego suma estos dos resultados
  3. **Módulo de vectores**:
	  * Suma los cuadrados de la componente x e y de un mismo vector, al resultado de esta operación aplica raíz cuadrada para obtener la magnitud del vector.

#### Pruebas realizadas
- Se realizaron pruebas de casos "extremos" en la entrada de datos de la interfaz para poner a prueba las fallas del programa, como por ejemplo:
	* Operaciones con números de más de 6 cifras, siendo enteros positivos y negativos.
	* Ingresar valores no compatibles con las funciones mencionadas, incluyendo el menú.
	* Números con varias cifras decimales.

### ¿Cómo utilizo este programa en mi PC?
Para poder ejecutar el Vectorinador en tu pc, se necesita utilizar un compilador compatible, en este caso se necesita gcc, y el proceso de compilación y ejecución es el siguiente:
1. Descargar los archivos en carpeta src, organizándolos una misma carpeta.
2. Ingresar en la terminal (también conocida como consola o cmd) y abrir ruta del directorio, como por ejemplo:
	1. cd Desktop
	2. cd Vectorinador 
3. Luego, ingresar el siguiente comando:
	* gcc main.c vectorinador.c -o Vectorinador -lm
4. Cuando compile exitosamente, se va a poder ejecutar en la misma consola con el siguiente comando:
	* ./Vectorinador
5. ¡Listo! el programa se ejecutará correctamente y mostrará en pantalla unos textos solicitando componentes x e y de cada vector.
6. Al proporcionar la información de ambos vectores se abrirá un menú donde se podrán utilizar las diferentes funcionalidades del programa.
7. Para utilizar las funciones de Vectorinador solamente se debe ingresar el número de la opción que se desea.
8. Finalmente, para finalizar la ejecución de Vectorinador, se debe ingresar el valor 0.

### Avance logrado y preparación hito 2.
Hasta el momento en hito 1, hemos logrado el funcionamiento de las operaciones básicas de vectores en 2 dimensiones, tales como suma, resta, producto punto entre vectores y obtener módulo, junto a un menú interactivo para acceder a estas funciones. Respecto a lo planteado para hito 2, sería adaptar el código a c++ para poder hacer uso de la función vector que posee esta versión, lo cual facilitaría el proceso, funcionamiento y complejidad del código y agregar funciones clave de operaciones entre vectores. Otro enfoque sería aumentar de la cantidad de vectores y el límite de dimensiones de estos para poder realizar operaciones más complejas.
