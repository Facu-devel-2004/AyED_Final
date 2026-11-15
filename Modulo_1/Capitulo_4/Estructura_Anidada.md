# Regla de Acceso

## Operador Punto (.) vs. Operador Flecha (->)
La eleccion del operador depende unicamente del tipo de la expresion situada a la izquierda:

- Si la izquierda hay una variable de estructura (valor), se utiliza el operador punto (.).

- Si a la izquierda hay un puntero a estructura, se utiliza el operador flecha (->), donde ptr->campo es exactamente equivalente a (* ptr).campo, donde sus parentesis son obligatorios porque el operador . tiene mayor precedencia que el operador * .

### Estructuras de referencia (`struct.cpp`)

```cpp
typedef struct {
  int dia, mes, anio;
} FECHA;

typedef struct {
  char nombre[20];
  FECHA nac; // Estructura anidada por valor dentro de persona
  long int dni;
} persona;
```

> Como `nac` es un miembro de tipo `FECHA` (una estructura directa, **no** un puntero), una vez que llegamos a `nac` siempre usamos `.dia` para acceder al día.

---

## Cuadro Comparativo

| Caso de Uso                         | Declaración                                             | Acceso al Nombre                    | Acceso al Día de Nacimiento           | Justificación Técnica                                                                                      |
| :---------------------------------- | :------------------------------------------------------ | :---------------------------------- | :------------------------------------ | :--------------------------------------------------------------------------------------------------------- |
| **Variable en Stack**               | `persona p1;`                                           | `p1.nombre`                         | `p1.nac.dia`                          | `p1` es estructura (`.`) y `p1.nac` también es estructura (`.`).                                           |
| **Puntero en Heap**                 | `persona *pp1 = (persona*)malloc(sizeof(persona));`     | `pp1->nombre`                       | `pp1->nac.dia`                        | `pp1` es puntero (`->`), pero su miembro `nac` es una estructura directa `FECHA`, por lo que lleva `.dia`. |
| **Arreglo dinámico**                | `persona *ps = (persona*)malloc(sizeof(persona)*N_PS);` | `(ps + i)->nombre` o `ps[i].nombre` | `(ps + i)->nac.dia` o `ps[i].nac.dia` | `ps + i` es un puntero al i-ésimo bloque (`->`), mientras que `ps[i]` ya está desreferenciado (`.`).       |
| **Pasaje a función (por puntero)**  | `void mostrar(persona *p)`                              | `p->nombre`                         | `p->nac.dia`                          | `p` recibe una dirección (`persona*`), por lo que usa `->` para `nombre` o `nac`, y `.dia` sobre `nac`.    |
| **Pasaje a función (valor / ref.)** | `void mostrar(persona p)` / `void mostrar(persona &p)`  | `p.nombre`                          | `p.nac.dia`                           | Tanto por valor (copia) como por referencia (alias), `p` es estructura directa y usa `.` en ambos niveles. |

---

## Desglose por caso y regla práctica

1. **Variable en Stack (`persona p1;`)**
   - `p1` es un `struct persona` directo -> `p1.nombre`.
   - `p1.nac` es un `struct FECHA` directo -> `p1.nac.dia`.

2. **Puntero en Heap (`persona *pp1`)**
   - `pp1` guarda una dirección de memoria (equivale a `(*pp1)`), por eso empieza con `->`: `pp1->nombre` y `pp1->nac`.
   - El resultado de `pp1->nac` ya es una estructura `FECHA` (no un puntero), así que el segundo acceso usa punto: `pp1->nac.dia`.

3. **Arreglo dinámico (`persona *ps`)**
   - Con aritmética de punteros, `(ps + i)` apunta al elemento `i` -> `(ps + i)->nac.dia`.
   - Con subíndice, `ps[i]` equivale a `*(ps + i)` (ya desreferenciado) -> `ps[i].nac.dia`.

4. **Pasaje a función (`void`)**
   - **Por puntero (`persona *p`)**: se pasa la dirección (ej. `mostrar(&p1)` o `mostrar(pp1)`). Dentro de la función se accede con `p->nombre` y `p->nac.dia`.
   - **Por referencia (`persona &p`) o por valor (`persona p`)**: dentro de la función `p` representa directamente a la estructura, por lo que se accede con `p.nombre` y `p.nac.dia` (con `&` modifica el original y evita copiar toda la estructura).

> **Regla rápida:** si a la izquierda hay un puntero/dirección usás `->`; si es la variable, una referencia o un `[i]`, usás `.`.
