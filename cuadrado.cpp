#include "cuadrado.h"
#include "utils.h"
#include <iostream>
using namespace std;

Cuadrado::Cuadrado(double a) : a(a) {}

void Cuadrado::dibujar() {
    string t = leerArchivo("cuadrado.txt");
    colorearPalabra(t, "Cuadrado", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{4\\*a\\}", 4 * a, 5, { VERDE });
    t = sustitucionRegex(t, "\\{aa\\^2\\}", a * a, 6, { VERDE });
    cout << t << "\n";
}
