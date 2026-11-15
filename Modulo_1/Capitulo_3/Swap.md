# Los 3 Mecanismos de Pasaje

C++ permite sobrecargar funciones para implementar 3 formas de pasaje.

1. Por VALOR:
   Opera sobre copias locales en el Stack, NO modifica x ni y en el main.
   void swap(int a, int b) {int c = a, a = b, b = c}

2. Por PUNTERO:
   Recibe direcciones (&x, &y) y desreferencia (*); SI modifica main.
   void swap(int *a, int *b) {int c = * a, * a = * b, * b = c}

3. Por REFERENCIA:
   a y b son alias directos de x e y; SI modifica en el main.
   void swap(int &a, int &b) {int c = a, a = b, b = c}

## Pila (Stack) vs. Monticulo (Heap)

- _Memoria Automatica (Stack):_
  Aloja variables locales y parametros de funciones (ej. int x = 4;), se gestiona automaticamente al entrar y salir del ambito de la funcion.

- _Memoria Dinamica (Heap):_
  Se solicita explicitamente en tiempo de ejecucion. En C++ se reserva con new y se libera con delete (o delete[] para arreglos) para evitar fugas de memoria.
