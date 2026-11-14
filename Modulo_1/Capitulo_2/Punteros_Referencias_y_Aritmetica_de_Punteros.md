# Punteros

Un puntero es una variable cuyo contenido es la direccion de memoria de otra variable. Su dominio se apoya en tres operadores escenciales:

- _Operador de Direccion (&)_:
  Devuelve la direccion de memoria donde reside una variable (ej. px = &x).

- *Operador de Indireccion o Desreferenciacion (**):
  Accede al valor almacenado en la direccion a la que apunta el puntero (ej. *px = 7). Si un puntero apunta a nullptr e intento desreferenciarlo el programa produce un fallo de segmentacion en tiempo de ejecicion.

- _Operador sizeof_:
  Determina en tiempo de compilacion la cantidad de bytes que ocupa un tipo de dato o variable en memoria (ej. sizeof(int) suele ser 4 bytes).

## Arreglos y Aritmetica de Punteros

El nombre de un arreglo (v) actua como un puntero constante a su primer elemento (&v[[0]]). Si declaramos "int v[[5]] = {23, 1, -8, 14, 7};", "int *px = &v[[0]];" e "int *py = v;", existen 4 formas de recorrer el arreglo en un ciclo "for (int i = 0; i < 5; i++)".

1. px[[i]]:
   Notacion de subindice estandar aplicada sobre un puntero.

2. *(px + i):
   Aritmetica de punteros sin modificar px; sumar un entero i a un puntero int * desplaza el calculo de la direccion en i x sizeof(int) bytes y luego desreferencia esa celda.

3. *(v + i):
   Desplazamiento aritmetico identico a partir de la direccion base constante v.

4. *py++:
   Por precedencia de operadores, el posincremento ++ aplica sobre la direccion py devolviendo su direccion actial para que * lea el dato, y acto seguido avanza el puntero al siguiente entero.
