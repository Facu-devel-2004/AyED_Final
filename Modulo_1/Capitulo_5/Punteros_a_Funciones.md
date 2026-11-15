# Callbacks

El codigo ejecutable de una funcion tambien reside en una direccion de memoria. Un puntero a funcion guarda la direccion de inicio de una funcion que posea una firma especifica y permite inyectar comportamiento dinamico dentro de un algoritmo.

```cpp
void burbuja(int trabajo[], const int tamano, bool (*compara)(int, int)) {
  for (int pasada = 1; pasada < tamano; pasada++){
    for (int cuenta = 0; cuenta < tamano - 1; cuenta++){
      if((*compara)(trabajo[cuenta], trabajo[cuenta + 1])){
        intercambia(&trabajo[cuenta], &trabajo[cuenta + 1]);
      }
    }
  }
}

//True si estan desordenados para orden ascendente
bool ascendente(int a, int b) { return b < a; }

//True si estan desordenados para orden descendentes
bool descendente(int a, int b) { return a < b; }
```

- _Atencion a la sintaxis de parentesis:_
  `bool (*compara)(int, int)` declara un puntero a funcion; si omito el parentesis de compara, estaria declarando una funcion que devuelve un puntero bool*.
