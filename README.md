# El-Vectorinador-10-000
### ¿Por qué? (problemática):
Existe una falta de herramientas interactivas que permitan visualizar las operaciones realizadas en el plano vectorial, lo que entorpece el aprendizaje de esta materia, que, al ser un concepto clave en el estudio de las ciencias básicas, es muy importante comprender y dominar.

### Objetivos generales:
Desarrollar un entorno claro en donde tanto alumnos como profesores puedan experimentar o comprobar los resultados de operaciones vectoriales, facilitando así la comprensión de este tema.

### Objetivos específicos:
- Traducir código a C++
- Añadir más operaciones vectoriales. 
- Posibilidad de modificar los vectores ingresados.
- Aumentar la dimensión de los vectores.
 
### Integrantes/Roles:
- **Damián Cabrera (Adrielazo)**: Control de calidad (tester) y administración de repositorio
- **Vicente Manríquez (Pilsenshot)**: Programación de lógica.
- **Martín Urrutia (kourzed):** Documentación y gestión.
- **Lukas Valenzuela (Lukakas16):** Programación de lógica.

### Funcionalidades implementadas y pruebas realizadas.

#### Funcionalidades:
Menú sencillo e interactivo donde se pueden escoger diferentes opciones, tales como:
1. **Registrar vectores:**
	* Crea un nuevo vector, el cual es añadido a una lista que contiene todos los vectores creados.
	* Ingresar exclusivamente números, en caso de ser decimales, estos se deben ingresar con un punto (ejemplo: 2,1 -> 2.1).
2. **Visualizar vectores registrados:**
	* Permite mostrar el pantalla el listado de vectores registrados en la memoria.
3. **Modificar vectores existentes:**
	* Habilita la edición de los valores de cada componente de un vector seleccionado.
4. **Entrar al menú para realizar operaciones vectoriales:**
	* Muestra en pantalla todas las operaciones vectoriales disponibles que se pueden realizar.

Respecto al menú de operaciones vectoriales tenemos:
1. **Suma y resta**:
	* Estas dos funciones trabajan sumando y/o restando las componentes (x, y, z) de cada vector, guardando este resultado para mostrarlo en pantalla. 
	* Funciones se pueden seleccionar por separado en el menú.
2. **Producto punto**:
	* Multiplica cada componente de cada vector, luego suma cada resultado de estas multiplicaciones para sumarlas y poder mostrar este resultado en pantalla, el cual es de tipo escalar.
3. **Producto cruz:**
	* Opera 2 vectores seleccionados mediante una matriz formada por las componentes de cada vector y vectores unitarios (i, j, k), obteniendo el determinante de esta, el cual se interpreta como las nuevas componentes del vector perpendicular al estos 2 vectores iniciales.
4. **Módulo del vector**:
	* Suma los cuadrados de la componente (x, y, z) de un vector seleccionado, al resultado de esta operación aplica raíz cuadrada para obtener la magnitud del vector, luego este resultado se muestra en pantalla.
5. **Volver al menú principal**

#### Pruebas realizadas:


### Cambios estructurales al migrar de C a C++:
- Al migrar de C a C++ se implementó la biblioteca vector, facilitando el manejo de estas entidades.
- Se utiliza la memoria interna del programa, evitando así el utilizar memoria dinámica y previniendo memory leaks.
- El lenguaje entiende de mejor manera los procesos matemáticos, por lo que los números grandes (que anteriormente el programa tenía errores al procesarlos) ya no presentan un problema, gracias que los presenta en el formato de notación científica con e, evitando ahora errores previos.

### Descripción de clases:
La clase vector encapsula las componentes (x, y, z), las cuales son privadas y evita que otro archivo pueda modificar el tipo de variable, es decir, estos valores se mantendrán en float. También engloba a las funciones (operaciones vectoriales), funcionando como una especie de molde para crear objetos que se comporten exactamente como un vector matemático.

### ¿Cómo ejecuto este programa en mi PC?
Para poder ejecutar el Vectorinador en tu pc, se necesita utilizar un compilador compatible, en este caso se necesitará tener instalado el compilador g++, y el proceso de compilación y ejecución es el siguiente:
1. Descargar los archivos en carpeta src, organizándolos una misma carpeta.
2. Ingresar en la terminal (también conocida como consola o cmd) y abrir ruta del directorio, como por ejemplo:
	1. cd Desktop
	2. cd src
3. Luego, ingresar el siguiente comando:
	* g++ main.cpp vectorinador10000.cpp -o Vectorinador (Linux)
	* g++ main.cpp vectorinador10000.cpp -o Vectorinador.exe (Windows)
4. Cuando compile exitosamente, se va a poder ejecutar en la misma consola con el siguiente comando:
	* ./Vectorinador
5. ¡Listo! el programa se ejecutará correctamente y mostrará en pantalla un menú con varias opciones, donde se podrán ingresar vectores, modificarlos y varias opciones.
6. Para utilizar una opción, basta con ingresar el número que se ve asociado a dicha opción.
	* Nota: no se deben ingresar valores que no sean admitidos, tales como:
		* Letras.
		* Carácteres no compatibles con el formato (: , ¨¨ # $ % etc...).
7. Luego de ingresar los vectores deseados dentro de este menú principal, se puede ingresar a otro menú en la opción de "Operar vectores".
8. En el menú de "Operar vectores" se encontrarán las diferentes operaciones vectoriales, las cuales fueron detalladas anteriormente en este documento.
9. Finalmente, para finalizar la ejecución del programa, se debe devolver al menú principal ingresando el número 6 e ingresar el número 5.
### Ejemplos de ejecución y resultados esperados:


### Avance logrado y pasos hacia Hito 3:


### Principales dificultades encontradas durante la migración del proyecto:
- El cambio de sintaxis, teniendo que reescribir líneas de código de una manera distinta.
- El uso de clases y la orientación a objetos que este lenguaje ofrece.

### Referencias:
- Para las funciones #ifndef y #endif: https://learn.microsoft.com/es-es/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=msvc-170
- Sintaxis de markdown: https://docs.github.com/es/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax
- Uso de vectores (cómo manejarlos, eliminación de contenido, etc...): https://en.cppreference.com/cpp/container/vector
