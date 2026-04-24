# El-Vectorinador-10-000
### ¿Por qué? (problemática)
Existe una falta de herramientas interactivas que permitan visualizar las operaciones realizadas en el plano vectorial, lo que entorpece el aprendizaje de esta materia, que, al ser un concepto clave en el estudio de las ciencias básicas, es muy importante comprender y dominar.

### Objetivos generales.
Desarrollar un entorno claro en donde tanto alumnos como profesores puedan experimentar o comprobar los resultados de operaciones vectoriales, facilitando así la comprensión de este tema.

### Objetivos específicos.
- Definir funciones de operaciones de vectores en 2 dimensiones: suma, resta, módulo y producto punto.
- Crear menú interactivo para el prototipo.
- 
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
