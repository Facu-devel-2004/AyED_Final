# Algoritmos y Estructuras de Datos (AyED)

Repositorio de estudio de la materia **Algoritmos y Estructuras de Datos (AyED)**. Reúne apuntes teóricos en Markdown, ejemplos de código en C++ y ejercicios prácticos organizados por módulos.

## Estructura del repositorio

```text
AyED/
├── README.md
└── Modulo_1/
    ├── Capitulo_1/
    ├── Capitulo_2/
    ├── Capitulo_3/
    ├── Capitulo_4/
    ├── Capitulo_5/
    ├── Capitulo_6/
    └── Ejercicios_Practicos/
```

## Módulos

### Módulo 1 — Fundamentos de C++, Gestión de Memoria y POO (`Modulo_1/`)

Introduce las bases del lenguaje C++, la organización de datos en memoria y la Programación Orientada a Objetos a lo largo de seis capítulos y una guía práctica:

- **Tipos de Datos y TAD**: diferencia entre tipos primitivos/compuestos, estructuras de datos y Tipos Abstractos de Datos (TAD).
- **Punteros y Aritmética de Punteros**: operadores `&`, `*`, `nullptr`, manejo de direcciones y recorrido de arreglos mediante aritmética de punteros.
- **Pasaje de Parámetros y Memoria**: comparación entre pasaje por valor, puntero y referencia, junto con el uso de memoria **Stack** y **Heap** (`new` / `delete` / `delete[]`).
- **Estructuras Anidadas**: definición de `struct` y reglas de acceso con `.` y `->` en Stack, Heap, arreglos dinámicos y funciones.
- **Punteros a Funciones**: uso de *callbacks* para parametrizar algoritmos (como criterios de ordenamiento).
- **Programación Orientada a Objetos (POO)**: encapsulamiento, constructores/destructores, composición de clases, herencia pública, polimorfismo y clases abstractas.
- **Ejercicios Prácticos (`Ejercicios_Practicos/`)**: prácticas en C++ que integran punteros y memoria dinámica, composición de clases, herencia y polimorfismo.

## Compilación y ejecución

Desde la raíz del repositorio, podés compilar y ejecutar cualquier archivo `.cpp` que cuente con una función `main()` usando `g++`:

```bash
g++ -std=c++17 -Wall -Wextra ruta/al/archivo.cpp -o programa
./programa
```

Por ejemplo:

```bash
g++ -std=c++17 -Wall -Wextra Modulo_1/Ejercicios_Practicos/ej1_punteros_modulos.cpp -o ej1
./ej1
```
