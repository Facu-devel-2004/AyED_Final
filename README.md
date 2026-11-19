# Algoritmos y Estructuras de Datos (AyED)

Repositorio de estudio de la materia **Algoritmos y Estructuras de Datos (AyED)**. Reúne apuntes teóricos en Markdown, ejemplos de código en C++ y ejercicios prácticos orientados al manejo de memoria, punteros, estructuras y Programación Orientada a Objetos (POO).

## Estructura actual del repositorio

```text
AyED/
├── README.md
└── Modulo_1/
    ├── Capitulo_1/
    │   └── Tipos_de_Datos.md
    ├── Capitulo_2/
    │   ├── Arreglo_Punteros.cpp
    │   ├── Punteros.cpp
    │   └── Punteros_Referencias_y_Aritmetica_de_Punteros.md
    ├── Capitulo_3/
    │   └── Swap.md
    ├── Capitulo_4/
    │   ├── Estructura_Anidada.md
    │   └── struct.cpp
    ├── Capitulo_5/
    │   └── Punteros_a_Funciones.md
    ├── Capitulo_6/
    │   └── POO.md
    └── Ejercicios_Practicos/
        ├── ej1_punteros_modulos.cpp
        ├── ej2_tiempo_semana.cpp
        └── ej3_herencia_polimorfismo.cpp
```

## Contenido del Módulo 1

### Capítulo 1 — Tipos de Datos y TAD (`Modulo_1/Capitulo_1/`)
- **`Tipos_de_Datos.md`**: Diferencia entre **Tipo de Dato** (primitivos y compuestos/agregados), **Estructura de Datos** (organización y relación en memoria) y **Tipo Abstracto de Datos (TAD)** (separación entre especificación e implementación como base de las clases en C++).

### Capítulo 2 — Punteros y Aritmética de Punteros (`Modulo_1/Capitulo_2/`)
- **`Punteros_Referencias_y_Aritmetica_de_Punteros.md`**: Operadores esenciales (`&`, `*`, `sizeof`), uso de `nullptr` y las 4 formas de recorrer un arreglo (`px[i]`, `*(px + i)`, `*(v + i)`, `*py++`).
- **`Punteros.cpp`**: Ejemplo práctico de declaración de punteros, desreferenciación y reasignación de direcciones.
- **`Arreglo_Punteros.cpp`**: Demostración ejecutable de las 4 formas de recorrer un arreglo usando subíndices y aritmética de punteros.

### Capítulo 3 — Pasaje de Parámetros y Memoria (`Modulo_1/Capitulo_3/`)
- **`Swap.md`**: Comparación de los 3 mecanismos de pasaje de parámetros en C++ (**por valor**, **por puntero** y **por referencia**) mediante la sobrecarga de `swap`, además de las diferencias entre memoria automática (**Stack**) y memoria dinámica (**Heap** con `new` / `delete` / `delete[]`).

### Capítulo 4 — Estructuras y Regla de Acceso (`Modulo_1/Capitulo_4/`)
- **`Estructura_Anidada.md`**: Regla de acceso con operador punto (`.`) vs. operador flecha (`->`) aplicada a estructuras simples y anidadas en Stack, Heap, arreglos dinámicos y pasaje a funciones.
- **`struct.cpp`**: Definición de las estructuras de referencia `FECHA` y `persona` (con `FECHA nac` anidada por valor).

### Capítulo 5 — Punteros a Funciones (`Modulo_1/Capitulo_5/`)
- **`Punteros_a_Funciones.md`**: Uso de punteros a funciones como *callbacks* para inyectar criterios de comparación (`ascendente` y `descendente`) dentro de un algoritmo de ordenamiento burbuja (`burbuja`).

### Capítulo 6 — Programación Orientada a Objetos (`Modulo_1/Capitulo_6/`)
- **`POO.md`**: Apunte de POO en C++ que abarca:
  - Encapsulamiento (`private` / `public`), constructores con argumentos predeterminados, destructores (`~Tiempo()`) y validación/acarreo horario.
  - Composición de clases (`Semana_Laboral` compuesta por objetos `Tiempo`).
  - Herencia pública (`Punto3` -> `Circulo4`), lista de inicializadores y redefinición de métodos (`Punto3::imprime()`).
  - Polimorfismo y clases abstractas mediante métodos virtuales puros (`virtual ... = 0`) y destructor virtual (`Sensor` y `SensorTemperatura`).

### Ejercicios Prácticos (`Modulo_1/Ejercicios_Practicos/`)
- **`ej1_punteros_modulos.cpp`**: Gestión dinámica de un arreglo de `ModuloNave` en el Heap, uso del operador flecha (`->`), intercambio por puntero, recorrido con puntero móvil y ordenamiento burbuja mediante punteros a funciones (`criterioConsumoAsc`, `criterioIdDesc`).
- **`ej2_tiempo_semana.cpp`**: Plantilla práctica con pruebas en `main()` para implementar la clase `Tiempo` (validación de rangos, acarreo en cascada en segundos/minutos/horas) y la clase compuesta `Semana_Laboral`.
- **`ej3_herencia_polimorfismo.cpp`**: Plantilla práctica con pruebas en `main()` dividida en dos partes: herencia pública (`Punto3` -> `Circulo4`) y polimorfismo con clases abstractas (`Sensor`, `SensorTemperatura` y `SensorPresion`).

## Cómo compilar y ejecutar los ejemplos y ejercicios

Desde la raíz del repositorio, podés compilar cualquier archivo `.cpp` que cuente con función `main()` usando `g++`:

```bash
# Ejemplo del Capítulo 2
g++ -std=c++17 -Wall -Wextra Modulo_1/Capitulo_2/Punteros.cpp -o punteros
./punteros

# Ejemplo de arreglos y punteros
g++ -std=c++17 -Wall -Wextra Modulo_1/Capitulo_2/Arreglo_Punteros.cpp -o arreglo_punteros
./arreglo_punteros

# Ejercicios prácticos
g++ -std=c++17 -Wall -Wextra Modulo_1/Ejercicios_Practicos/ej1_punteros_modulos.cpp -o ej1
./ej1

g++ -std=c++17 -Wall -Wextra Modulo_1/Ejercicios_Practicos/ej2_tiempo_semana.cpp -o ej2
./ej2

g++ -std=c++17 -Wall -Wextra Modulo_1/Ejercicios_Practicos/ej3_herencia_polimorfismo.cpp -o ej3
./ej3
```

> **Nota:** `Modulo_1/Capitulo_4/struct.cpp` contiene únicamente las definiciones de las estructuras `FECHA` y `persona` (sin `main()`), por lo que no se compila como ejecutable independiente.
