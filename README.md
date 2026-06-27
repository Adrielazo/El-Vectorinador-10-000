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
La interfaz tiene como objetivo proveer un entorno accesible de "Panel de control + Canvas".
* **Widgets principales:** Cuenta con cajas de texto para los inputs de coordenadas, un apartado para poder ver la memoria de vectores y una lista desplegable agrupando las distintas operaciones matemáticas.
* **Flujo de uso:** El usuario interactúa con los menús laterales para registrar sus vectores. Al hacer clic en una operación, la interfaz envía los parámetros a las funciones de cálculo y proyecta gráficamente la operación resultante en el lienzo principal (visualizador 2D/3D).

### Separación entre lógica e interfaz:
La clase Vector original de C++ y los archivos de cálculo matemático están desacoplados del entorno gráfico. La interfaz en Qt simplemente capta los datos de las cajas de texto, instancia los objetos desde la clase Vector, llama a las operaciones matemáticas (ej. calcular un producto cruz) y finalmente lee los resultados para poder "dibujar" las líneas y mostrar los valores resultantes por pantalla, sin realizar cálculos directamente en los elementos visuales.

### ¿Cómo ejecuto este programa en mi PC?
Para poder ejecutar El Vectorinador 10000 en tu pc, deberás seguir los pasos a continuación:
1. Descargar el repositorio en su computadora.
2. Abrir **Qt Creator**.
3. Seleccionar la opción de "Abrir proyecto" y cargar el archivo `.pro` o `CMakeLists.txt` del directorio.
4. Seleccionar el compilador (Kit) configurado en Qt.
5. Hacer clic en el botón **Run** (icono verde de "Play" o `Ctrl+R`). El entorno compilará la lógica en C++ junto a la interfaz y desplegará la ventana del programa automáticamente.

### Principales dificultades en la integración de la interfaz:
El mayor desafío de integración fue acoplar las estructuras de vectores de C++ nativo con el ecosistema y librerías gráficas de Qt para lograr un dibujado 2D y 3D (principalmente 3D) en tiempo real que fuera fluido y sin caídas.
### Conclusiones del proyecto y posibles mejoras en un futuro:
- Se logró la meta planteada superando las limitaciones del entorno de consola y el paso a un entorno de visualización gráfica.
- Como mejora futura, la aplicación podría exportar los pasos matemáticos completos (el procedimiento de la matriz, la suma de componentes, etc.) a un archivo `.txt` de reporte, o incorporar animaciones que muestren las transformaciones de los vectores en tiempo real dentro del visualizador 3D.

### Referencias:
- Para el uso de directivas `#ifndef` y `#endif`: [Microsoft Learn](https://learn.microsoft.com/es-es/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=msvc-170).
- Sintaxis de Markdown para este archivo: [GitHub Markdown](https://docs.github.com/es/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).
- Uso de la biblioteca `vector` en C++ (manejo y eliminación de contenido): [Vectores](https://en.cppreference.com/cpp/container/vector).
