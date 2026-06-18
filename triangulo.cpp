#include "triangulo.h"
#include "utils.h"
#include <iostream>
using namespace std;

Triangulo::Triangulo(double a, double b, double c, double h) : a(a), b(b), c(c), h(h) {}

void Triangulo::dibujar() {
    string t = leerArchivo("triangulo.txt");
    colorearPalabra(t, "Triángulo", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{ccc\\}", c, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{hhh\\}", h, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{a\\+b\\+c\\}", a + b + c, 7, { VERDE });
    t = sustitucionRegex(t, "\\{bb\\*hh/2\\}", (b * h) / 2.0, 9, { VERDE });
    cout << t << "\n";
}
