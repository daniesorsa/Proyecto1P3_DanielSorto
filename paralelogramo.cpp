#include "paralelogramo.h"
#include "utils.h"
#include <iostream>
using namespace std;

Paralelogramo::Paralelogramo(double a, double b, double h) : a(a), b(b), h(h) {}

void Paralelogramo::dibujar() {
    string t = leerArchivo("paralelogramo.txt");
    colorearPalabra(t, "Paralelogramo", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{hhh\\}", h, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{a\\+b\\}", a + b, 5, { AZUL });
    t = sustitucionRegex(t, "\\{2\\*\\(a\\+b\\)\\}", 2 * (a + b), 9, { VERDE });
    t = sustitucionRegex(t, "\\{bb\\*hh\\}", b * h, 7, { VERDE });
    cout << t << "\n";
}
