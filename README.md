# El-Vectorinador-10-000

### Problemática a solucionar
Existe una falta de herramientas interactivas que permitan visualizar las operaciones realizadas en el plano vectorial, lo que entorpece el aprendizaje de esta materia, que, al ser un concepto clave en el estudio de las ciencias básicas, es muy importante comprender y dominar.

### Objetivos generales:
Desarrollar un entorno claro en donde tanto alumnos como profesores puedan experimentar o comprobar los resultados de operaciones vectoriales, facilitando así la comprensión de este tema con la creación de un visualizador interactivo en 2D y 3D.

### Objetivos específicos:
* Implementar el código C++ en Qt Creator para desarrollar la interfaz gráfica y visualizar las operaciones de manera geométrica (2D y 3D).
* Crear una interfaz de usuario (UI) intuitiva y fácil de entender.
* Correcto funcionamiento de ambos ambientes (2D y 3D).

### Integrantes/Roles:
* **Damián Cabrera (Adrielazo):** Control de calidad (tester) y administración de repositorio.
* **Vicente Manríquez (Pilsenshot):** Programación de integración de interfaz gráfica en Qt
* **Martín Urrutia (kourzed):** Documentación y gestión.
* **Lukas Valenzuela (Lukakas16):** Programación de lógica y corrección de errores.

### Descripción de las funcionalidades implementadas:
**Funcionalidades:**
* **Registro:** Permite crear nuevos vectores (ingresando números o decimales) que se añaden a una lista global en memoria (es visible en todo momento), los cuales luego pueden ser visualizados en pantalla.
   - En caso de ser decimales, estos se deben ingresar con un punto (ejemplo: 2,1 -> 2.1).
* **Modificación:** Habilita la edición de los valores de cada componente de un vector seleccionado.
* **Operaciones vectoriales disponibles:**
   - **Producto por un escalar:** Multiplica un vector por un número ingresado (fracciones deben ser en formato decimal, ya que no se acepta el *slash* `/`).
   - **Suma y resta:** Trabajan sumando/restando las componentes (x, y, z).
   - **Producto punto:** Multiplicación de las componentes de dos vectores seleccionados, dando un resultado escalar.
   - **Producto cruz:** Calcula un vector perpendicular a dos vectores seleccionados, incluyendo sus componentes en (x, y, z).
   - **Otras operaciones:** Módulo del vector (raíz cuadrada de suma de cuadrados), Vector unitario y Ángulo entre vectores (mediante la función *arccos*).

### Pruebas realizadas:
* Vectores con números de varias cifras en las componentes para analizar el comportamiento de estos en el entorno 2D y 3D.
* Ingreso de elementos no aceptados por el programa (como letras o carácteres especiales).

### Evolución del proyecto desde Hito 1 hasta Hito 3:
* **Hito 1:** El proyecto empezó en C siendo un programa ejecutable enteramente en consola, enfocado puramente en las matemáticas.
* **Hito 2:** El código fue traducido a C++. Se implementó la biblioteca `vector` para facilitar el manejo de entidades y se empezó a utilizar la memoria interna del programa para evitar el uso de memoria dinámica y prevenir *memory leaks*. C++ mejoró el procesamiento matemático de números grandes presentándolos en notación científica, evitando errores previos.
* **Hito 3:** Con la lógica de C++ ya estable, el código fue llevado a Qt Creator. Se abandonó la consola interactiva a favor de una interfaz de usuario (UI) completa con un motor de renderizado que permite visualizar los vectores en un espacio 2D y 3D, concretando la meta final del proyecto.

### Descripción de clases:
* **Vector:** Encapsula las componentes `(x, y, z)`, las cuales son privadas, evitando que otro archivo modifique su tipo (se mantienen en `float`). Esta clase engloba todas las operaciones vectoriales, funcionando como un molde para crear objetos que se comportan como vectores matemáticos.
* **Clases de Interfaz (MainWindow / Visualizador en Qt):** Son las responsables de inicializar la ventana, conectar las señales de los botones (interacciones del usuario) con el *backend* matemático de C++ y renderizar los modelos 2D y 3D en el *canvas* central.
* **VectorCanvas:** Se encarga de "traducir" los vectores creados para poder visualizar en pantalla, dándoles forma, dirección y color.

### Descripción de Interfaz (UI):

### Separación entre lógica e interfaz:

### ¿Cómo ejecuto este programa en mi PC?

### Ejemplos de ejecución y resultados esperados:

### Principales dificultades en la integración de la interfaz:

### Conclusiones del proyecto:

### Referencias:
- Para el uso de directivas `#ifndef` y `#endif`: [Microsoft Learn](https://learn.microsoft.com/es-es/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=msvc-170).
- Sintaxis de Markdown para este archivo: [GitHub Markdown](https://docs.github.com/es/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).
- Uso de la biblioteca `vector` en C++ (manejo y eliminación de contenido): [Vectores](https://en.cppreference.com/cpp/container/vector).
