# Programacion Orientada a Objetos

La POO agrupa en una clase class tanto el estado (atributos o mienbros de datos) como el comportamiento (metodos o funciones miembro).

## Encapsulamiento, Constructores, Destructores y Validacion

- _Ocultamiento de Informacion (private vs. public):_
  Los atributos se declaran private para impedor modificaciones invalidas desde afuera y se manipulan mediante metodos public (getters y setters) vinculados a la clase con el operador de resolucion de ambito.

- _Constructor con Argumentos Predeterminados:_
  Un prototipo como `Tiempo(int = 0, int = 0, int = 0);` permite instanciar objetos con 0, 1, 2 o 3 argumentos.

- _Destructor (~Tiempo()):_
  No recibe parametros ni retorna valor. Para objetos automaticos en el Stack, se ejecuta automaticamente al cerrarse la llave } de su ambito en orden inverso al de su construccion; para objetos dinamicos creados en el Heap, el destructor solo se ejecuta cuando se llama explicitamente a `delete p;`.

- _Invariante de Clase y Acarreo Horario:_
  Los setters validan el rango con el operador ternario `hora = (h >= 0 && h < 24) ? h : 0;`, el formateo usa <iomanip> (`setfill('0')` es persistente, mientras que `setw(2)` debe repetirse antes de cada valor), y el incremento de segundos aplica aritmetica modular `(obtieneSegundo() + 1) % 60`, disparando en cascada `incrementaMinutos(1)` cuando el segundo vuelve a 0.

## Composicion de Clases

La composicion ocurre cuando una clase incluye objetos de otra clase como miembros de datos:

```cpp
class Semana_Laboral {
private:
    string nombre;
    double dni;
    Tiempo T[5][2];     // 5 días (filas 0..4) x 2 fichadas (col 0: entrada, col 1: salida)
    Tiempo total_horas;
public:
    void set_entrada(int = 0, int = 0, int = 0, int = 0);
    void set_salida(int = 0, int = 0, int = 0, int = 0);
    Tiempo get_total_horas();
};
```

- _Construccion Automatica de Miembros:_
  Al instanciar el objeto Semana_Laboral, el constructor por defecto de Tiempo se ejecuta automaticamente 11 veces (10 veces por la matriz, y 1 por el 2do objeto).

## Herencia Publica y Polimorfismo

En la herencia publica `class Circulo4 : public Punto3`, la clase derivada Circulo4 hereda los atributos y metodos de la clase base Punto3 y agrega sus propios miembros radio:

```cpp
class Punto3 {
private:
    int x, y;
public:
    Punto3(int valorX = 0, int valorY = 0) : x(valorX), y(valorY) {} // Lista de inicializadores

    void estableceX(int valorX) {
      x = valorX;
    }

    int obtieneX() const {
      return x;
    }                               // Método const: no altera el objeto

    void estableceY(int valorY) {
      y = valorY;
    }

    int obtieneY() const {
      return y;
    }

    void imprime() const {
      cout << '[' << obtieneX() << ", " << obtieneY() << ']';
    }
};

class Circulo4 : public Punto3 {
private:
    double radio;
public:
    // Invoca primero al constructor de la clase base Punto3 mediante la lista de inicializadores
    Circulo4(int x = 0, int y = 0, double r = 0.0) : Punto3(x, y) {
        estableceRadio(r);
    }

    void estableceRadio(double r) {
      radio = (r < 0.0 ? 0.0 : r);
    }

    double obtieneRadio() const {
      return radio;
    }

    void imprime() const {
      cout << "Centro = ";
      Punto3::imprime(); // OBLIGATORIO usar Punto3:: para no causar recursión infinita
      cout << "; Radio = " << obtieneRadio();
    }
};
```

- _Accesibilidad (private vs. protected):_
  Aunque Circulo4 hereda x e y, al ser private en Punto3, Circulo4 solo puede leerlos o modificarlos mediantes los metodos publicos del Objeto Punto3.

- _Polimorfismo y Clases Abstractas (Parcial FCEFyN):_
  Cuando se necesita manipular distintos tipos derivados a traves de un puntero o referencia a la clase base, la clase base declara metodos virtual (o virtuales puros = 0, convirtiendose en una clase abstracta) y un destructor virtual.

```cpp
class Sensor {
public:
    virtual const string& leer() const = 0; // Método virtual puro (interfaz polimórfica)
    virtual ~Sensor() = default;            // Destructor virtual obligatorio en polimorfismo
};

class SensorTemperatura : public Sensor {
private:
    string temp;
public:
    SensorTemperatura() : temp("Temperatura") {}

    const string& leer() const override {
      return temp;
    }
};
```
