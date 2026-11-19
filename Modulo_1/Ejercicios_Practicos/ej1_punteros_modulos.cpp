#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct ModuloNave {
    int id;
    char nombre[25];
    double consumoMW;
};

// DONE: Implementar aquí
// Asignar los campos usando el operador flecha (->).
// Para 'nombre', usar strncpy (asegurando '\0' al final en nombre[24]) o copia manual.
void cargarModulo(ModuloNave *m, int id, const char* nom, double consumo) {
    m -> id = id;
    strncpy(m -> nombre, nom, 24);
    m -> consumoMW = consumo;
}

// DONE: Implementar aquí
// Intercambiar los CONTENIDOS apuntados por 'a' y 'b' usando un auxiliar ModuloNave.
// (Cuidado: NO intercambiar solo las copias locales de los punteros a y b).
void intercambiar(ModuloNave *a, ModuloNave *b) {
    ModuloNave c = *a;
    *a = *b;
    *b = c;
}

// DONE: Implementar aquí
// Retorna true si están en DESORDEN para ordenamiento ascendente por consumoMW
// (es decir, si el siguiente 'b' tiene menor consumoMW que el actual 'a').
bool criterioConsumoAsc(const ModuloNave &a, const ModuloNave &b) {
    if(b.consumoMW < a.consumoMW){
    return true;
  }
  return false;
}

// DONE: Implementar aquí
// Retorna true si están en DESORDEN para ordenamiento descendente por id.
bool criterioIdDesc(const ModuloNave &a, const ModuloNave &b) {
    if(b.id > a.id){
    return true;
  }
  return false;
}

// FIX: Implementar aquí
// Algoritmo burbuja que recorra el arreglo usando aritmética de punteros *(v + j)
// e invoque al puntero a función (*compara)(*(v + j), *(v + j + 1)) y a intercambiar(v + j, v + j + 1).
void ordenarModulos(ModuloNave *v, int n, bool (*compara)(const ModuloNave&, const ModuloNave&)) {
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n - 1; j++){
        ModuloNave Primero = *(v + j);
        ModuloNave Segundo = *(v + j + 1);
        if((*compara)(Primero, Segundo)){
          intercambiar(&Primero, &Segundo);
      }
    }
  }
}

// DONE: Implementar aquí
// Recorrer el arreglo usando un puntero móvil: const ModuloNave *p = v;
// avanzando con p++ e imprimiendo p->id, p->nombre y p->consumoMW.
void imprimirModulos(const ModuloNave *v, int n) {
    const ModuloNave *p = v;
    for(int i = 0; i < n - 1; i++){
      cout << p -> id << endl;
      cout << p -> nombre << endl;
      cout << p -> consumoMW << endl;
      p++;
  }
}

int main() {
    const int n = 4;

    // Reserva dinámica en el Heap (inicializada en cero para evitar basura antes de implementar cargarModulo)
    ModuloNave *flota = new ModuloNave[n]();

    cargarModulo(flota + 0, 102, "SensorTermico", 4.5);
    cargarModulo(flota + 1, 105, "Propulsor", 18.2);
    cargarModulo(flota + 2, 101, "CamaraOptica", 2.1);
    cargarModulo(flota + 3, 104, "ReactorAux", 12.0);

    cout << fixed << setprecision(1);

    cout << "=== PRUEBA 1: Ordenamiento por consumoMW (Ascendente) ===" << endl;
    ordenarModulos(flota, n, criterioConsumoAsc);
    cout << "[ESPERADO] Orden por consumo: 101 CamaraOptica (2.1 MW) -> 102 SensorTermico (4.5 MW) -> 104 ReactorAux (12.0 MW) -> 105 Propulsor (18.2 MW)" << endl;
    cout << "[OBTENIDO]" << endl;
    imprimirModulos(flota, n);
    cout << endl;

    cout << "=== PRUEBA 2: Ordenamiento por id (Descendente) ===" << endl;
    ordenarModulos(flota, n, criterioIdDesc);
    cout << "[ESPERADO] Orden por ID: 105 Propulsor (18.2 MW) -> 104 ReactorAux (12.0 MW) -> 102 SensorTermico (4.5 MW) -> 101 CamaraOptica (2.1 MW)" << endl;
    cout << "[OBTENIDO]" << endl;
    imprimirModulos(flota, n);
    cout << endl;

    // Liberación de memoria dinámica
    delete[] flota;
    flota = nullptr;

    return 0;
}
