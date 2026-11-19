#include <iostream>
#include <iomanip>
#include <string>

class Tiempo {
private:
    int hora;
    int minuto;
    int segundo;

public:
    Tiempo(int hr = 0, int min = 0, int seg = 0);

    void estableceHora(int h, int m, int s);
    void estableceHora1(int h);
    void estableceMinuto(int m);
    void estableceSegundo(int s);

    // Setter sin límite de 24 hs para acumulados semanales
    void set_hora(int h);

    // Getters provistos por la cátedra
    int obtieneHora1() const { return hora; }
    int obtieneMinuto() const { return minuto; }
    int obtieneSegundo() const { return segundo; }

    // Métodos de incremento con acarreo en cascada
    void incrementaSegundos(const int cuenta);
    void incrementaMinutos(const int cuenta);
    void incrementaHoras(const int cuenta);

    // Métodos de visualización provistos por la cátedra
    void imprimeUniversal() const {
        std::cout << std::setfill('0') << std::setw(2) << hora << ":"
                  << std::setw(2) << minuto << ":"
                  << std::setw(2) << segundo;
    }

    void imprimeEstandar() const {
        std::cout << ((hora == 0 || hora == 12) ? 12 : hora % 12) << ":"
                  << std::setfill('0') << std::setw(2) << minuto << ":"
                  << std::setw(2) << segundo
                  << (hora < 12 ? " AM" : " PM");
    }
};

// TODO: Implementar aquí
// Invocar a estableceHora(hr, min, seg)
Tiempo::Tiempo(int hr, int min, int seg) {
    (void)hr;
    (void)min;
    (void)seg;
    hora = 0;
    minuto = 0;
    segundo = 0;
}

// TODO: Implementar aquí
// Invocar a estableceHora1(h), estableceMinuto(m) y estableceSegundo(s)
void Tiempo::estableceHora(int h, int m, int s) {
    (void)h;
    (void)m;
    (void)s;
}

// TODO: Implementar aquí
// Validación ternaria: rango válido 0..23 (si es inválido, asignar 0)
void Tiempo::estableceHora1(int h) {
    (void)h;
}

// TODO: Implementar aquí
// Validación ternaria: rango válido 0..59 (si es inválido, asignar 0)
void Tiempo::estableceMinuto(int m) {
    (void)m;
}

// TODO: Implementar aquí
// Validación ternaria: rango válido 0..59 (si es inválido, asignar 0)
void Tiempo::estableceSegundo(int s) {
    (void)s;
}

// TODO: Implementar aquí
// Asignar 'hora' sin límite de 24 hs (validar que h >= 0; si es negativo, 0)
void Tiempo::set_hora(int h) {
    (void)h;
}

// TODO: Implementar aquí
// Incrementar 'cuenta' veces de a 1 segundo aplicando aritmética modular (% 60)
// y disparando incrementaMinutos(1) en cascada cuando el segundo vuelve a 0.
void Tiempo::incrementaSegundos(const int cuenta) {
    (void)cuenta;
}

// TODO: Implementar aquí
// Incrementar 'cuenta' veces de a 1 minuto aplicando aritmética modular (% 60)
// y disparando incrementaHoras(1) en cascada cuando el minuto vuelve a 0.
void Tiempo::incrementaMinutos(const int cuenta) {
    (void)cuenta;
}

// TODO: Implementar aquí
// Incrementar 'cuenta' horas aplicando aritmética modular (% 24).
void Tiempo::incrementaHoras(const int cuenta) {
    (void)cuenta;
}

// -----------------------------------------------------------------------------

class Semana_Laboral {
private:
    std::string nombre;
    long int dni;
    Tiempo T[5][2];     // 5 días (filas 0..4) x 2 fichadas (col 0: entrada, col 1: salida)
    Tiempo total_horas;

public:
    Semana_Laboral(const std::string& nom = "", long int d = 0) : nombre(nom), dni(d) {}

    void set_entrada(int dia, int h, int m, int s);
    void set_salida(int dia, int h, int m, int s);
    Tiempo get_total_horas();
};

// TODO: Implementar aquí
// Cargar en T[dia][0] la hora de entrada usando estableceHora(h, m, s) (validar dia en 0..4)
void Semana_Laboral::set_entrada(int dia, int h, int m, int s) {
    (void)dia;
    (void)h;
    (void)m;
    (void)s;
}

// TODO: Implementar aquí
// Cargar en T[dia][1] la hora de salida usando estableceHora(h, m, s) (validar dia en 0..4)
void Semana_Laboral::set_salida(int dia, int h, int m, int s) {
    (void)dia;
    (void)h;
    (void)m;
    (void)s;
}

// TODO: Implementar aquí
// Calcular para los 5 días la diferencia en segundos entre salida (col 1) y entrada (col 0),
// acumularla, reconvertir el total a horas, minutos y segundos, cargarlo en total_horas
// (usando set_hora para no truncar si supera 24 hs, y estableceMinuto / estableceSegundo)
// y retornar total_horas.
Tiempo Semana_Laboral::get_total_horas() {
    return total_horas; // Retorno dummy para compilación inicial
}

int main() {
    std::cout << "=== PRUEBA 1: Acarreo horario en Tiempo ===" << std::endl;
    Tiempo t(23, 59, 50);
    t.incrementaSegundos(25);

    std::cout << "[ESPERADO] Universal: 00:00:15 | Estandar: 12:00:15 AM" << std::endl;
    std::cout << "[OBTENIDO] Universal: ";
    t.imprimeUniversal();
    std::cout << " | Estandar: ";
    t.imprimeEstandar();
    std::cout << std::endl << std::endl;

    std::cout << "=== PRUEBA 2: Composicion en Semana_Laboral ===" << std::endl;
    Semana_Laboral s("Operario", 12345678);
    for (int dia = 0; dia < 5; ++dia) {
        s.set_entrada(dia, 8, 0, 0);
        s.set_salida(dia, 18, 20, 40);
    }

    Tiempo ht = s.get_total_horas();
    std::cout << "[ESPERADO] Total semanal: 51:43:20" << std::endl;
    std::cout << "[OBTENIDO] Total semanal: ";
    ht.imprimeUniversal();
    std::cout << std::endl;

    return 0;
}
