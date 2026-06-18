#include "circulo.h"
#include "utils.h"
#include <iostream>
using namespace std;

Circulo::Circulo(double r) : r(r) {}

void Circulo::dibujar() {
    string t = leerArchivo("circulo.txt");
    colorearPalabra(t, "Círculo", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    const double pi = 3.14159265359;
    t = sustitucionRegex(t, "\\{rrr\\}", r, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{2\\*pi\\*r\\}", 2 * pi * r, 8, { VERDE });
    t = sustitucionRegex(t, "\\{pi\\*r\\^2\\}", pi * (r * r), 8, { VERDE });
    cout << t << "\n";
}
