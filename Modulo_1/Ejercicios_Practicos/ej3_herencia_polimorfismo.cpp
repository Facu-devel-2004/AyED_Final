#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>

// =============================================================================
// PARTE A: Herencia Pública (Punto3 -> Circulo4)
// =============================================================================

class Punto3 {
private:
    int x;
    int y;

public:
    Punto3(int valorX = 0, int valorY = 0) : x(valorX), y(valorY) {}

    void estableceX(int valorX) { x = valorX; }
    int obtieneX() const { return x; }

    void estableceY(int valorY) { y = valorY; }
    int obtieneY() const { return y; }

    void imprime() const {
        std::cout << '[' << obtieneX() << ", " << obtieneY() << ']';
    }

    // TODO: Implementar aquí
    // Desplazar las coordenadas del punto sumando dx a x y dy a y
    // (usar estableceX/obtieneX y estableceY/obtieneY).
    void desplazar(int dx, int dy) {
        (void)dx;
        (void)dy;
    }
};

class Circulo4 : public Punto3 {
private:
    double radio;

public:
    // TODO: Implementar aquí
    // Invocar al constructor de la clase base : Punto3(x, y) y asignar el radio con estableceRadio(r).
    Circulo4(int x = 0, int y = 0, double r = 0.0) : Punto3(x, y) {
        (void)r;
        radio = 0.0; // Inicialización dummy para compilación inicial
    }

    // TODO: Implementar aquí
    // Validar que r >= 0.0 (si es negativo, asignar 0.0).
    void estableceRadio(double r) {
        (void)r;
    }

    // TODO: Implementar aquí
    double obtieneRadio() const {
        return 0.0; // Retorno dummy
    }

    // TODO: Implementar aquí
    double obtieneDiametro() const {
        return 0.0; // Retorno dummy
    }

    // TODO: Implementar aquí
    double obtieneCircunferencia() const {
        return 0.0; // Retorno dummy
    }

    // TODO: Implementar aquí
    double obtieneArea() const {
        return 0.0; // Retorno dummy
    }

    // TODO: Implementar aquí
    // Redefinición: imprimir "Centro = ", invocar a Punto3::imprime() (obligatorio usar Punto3::
    // para evitar recursión infinita) e imprimir "; Radio = " seguido de obtieneRadio().
    void imprime() const {
    }

    // TODO: Implementar aquí
    // Incrementar el radio actual en el porcentaje indicado (ej: 20.0 suma un 20% al radio).
    void incrementarRadioPorcentaje(double porcentaje) {
        (void)porcentaje;
    }

    // TODO: Implementar aquí
    // Retornar el perímetro de la semicircunferencia: arco (pi * r) + diámetro (2 * r).
    // Podés usar la constante M_PI (de <cmath>) o 3.14159265358979323846.
    double obtienePerimetroSemicircunferencia() const {
        return 0.0; // Retorno dummy
    }
};

// =============================================================================
// PARTE B: Polimorfismo con Clases Abstractas (Sensor)
// =============================================================================

class Sensor {
public:
    virtual const std::string& leer() const = 0;
    virtual ~Sensor() = default;
};

// TODO: Implementar aquí
// Declarar e implementar las clases derivadas:
// - SensorTemperatura : public Sensor -> leer() retorna una referencia constante a "Temperatura"
// - SensorPresion     : public Sensor -> leer() retorna una referencia constante a "Presion"
// Recordar usar 'override' en leer() const y guardar el std::string como atributo de la clase
// para devolver una referencia válida (no a una variable local temporal).

// =============================================================================
// MAIN: Casos de prueba automatizados
// =============================================================================

int main() {
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "=== PARTE A.1: Objeto Circulo4 en Stack ===" << std::endl;
    Circulo4 c1(10, 10, 5.0);
    std::cout << "[ESPERADO] Inicial: Centro = [10, 10]; Radio = 5.0000" << std::endl;
    std::cout << "[OBTENIDO] Inicial: ";
    c1.imprime();
    std::cout << std::endl;

    c1.desplazar(5, -3);
    c1.incrementarRadioPorcentaje(20.0);
    std::cout << "[ESPERADO] Tras desplazar(5, -3) y +20% radio: Centro = [15, 7]; Radio = 6.0000" << std::endl;
    std::cout << "[OBTENIDO] Tras desplazar(5, -3) y +20% radio: ";
    c1.imprime();
    std::cout << std::endl;

    std::cout << "[ESPERADO] Perimetro semicircunferencia (r=6): 30.8496" << std::endl;
    std::cout << "[OBTENIDO] Perimetro semicircunferencia (r=6): "
              << c1.obtienePerimetroSemicircunferencia() << std::endl << std::endl;

    std::cout << "=== PARTE A.2: Puntero a Circulo4 en Heap ===" << std::endl;
    Circulo4 *c2 = new Circulo4(37, 43, 2.5);
    std::cout << "[ESPERADO] Radio con c2->obtieneRadio():    2.5000" << std::endl;
    std::cout << "[OBTENIDO] Radio con c2->obtieneRadio():    " << c2->obtieneRadio() << std::endl;
    std::cout << "[ESPERADO] Radio con (*c2).obtieneRadio():  2.5000" << std::endl;
    std::cout << "[OBTENIDO] Radio con (*c2).obtieneRadio():  " << (*c2).obtieneRadio() << std::endl;
    std::cout << "[ESPERADO] Diametro=5.0000 | Circunf=15.7080 | Area=19.6350 | SemiPerim=12.8540" << std::endl;
    std::cout << "[OBTENIDO] Diametro=" << c2->obtieneDiametro()
              << " | Circunf=" << c2->obtieneCircunferencia()
              << " | Area=" << c2->obtieneArea()
              << " | SemiPerim=" << c2->obtienePerimetroSemicircunferencia() << std::endl;
    delete c2;
    c2 = nullptr;
    std::cout << std::endl;

    std::cout << "=== PARTE B: Polimorfismo con Sensor ===" << std::endl;
    std::cout << "(Descomenta el bloque siguiente cuando implementes SensorTemperatura y SensorPresion)" << std::endl;
    /*
    std::vector<Sensor*> sensores;
    sensores.push_back(new SensorTemperatura());
    sensores.push_back(new SensorPresion());

    std::cout << "[ESPERADO] Temperatura | Presion" << std::endl;
    std::cout << "[OBTENIDO] ";
    for (std::size_t i = 0; i < sensores.size(); ++i) {
        std::cout << sensores[i]->leer();
        if (i + 1 < sensores.size()) {
            std::cout << " | ";
        }
    }
    std::cout << std::endl;

    for (Sensor* s : sensores) {
        delete s;
    }
    sensores.clear();
    */

    return 0;
}
