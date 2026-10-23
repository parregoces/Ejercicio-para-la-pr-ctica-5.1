#include <iostream>
#include <fstream>
#include "particula.h"

using namespace std;

int main() {
    // Archivo para guardar posiciones
    ofstream archivo("trayectoria_particula.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." <<endl;
        return 1;
    }

    // Parámetros iniciales
    double xIn = 5;
    double yIn = 10;
    double velIn = 30;
    double ang = 45;
    double g = 9.81;

    // Dimensiones (como límites de la “escena”)
    double ancho = 900;
    double alto = 700;

    // Crear la partícula
    particula p(xIn, yIn, velIn, ang, g);

    double dt = 1;

    // Simulación
    while (!p.estaQuieto()) {
        p.actualizarPosicion(dt, ancho, alto, archivo);
    }

    archivo.close();
    cout << "Simulación completada. Datos guardados en trayectoria_particula.txt\n";
    return 0;
}
