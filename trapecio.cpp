#include "trapecio.h"
#include "utils.h"
#include <iostream>
using namespace std;

Trapecio::Trapecio(double a, double b, double c, double h, double B) : a(a), b(b), c(c), h(h), B(B) {}

void Trapecio::dibujar() {
    string t = leerArchivo("trapecio.txt");
    colorearPalabra(t, "Trapecio", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{ccc\\}", c, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{hhh\\}", h, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{BBB\\}", B, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{B\\+b\\+a\\+c\\}", B + b + a + c, 9, { VERDE });
    t = sustitucionRegex(t, "\\{\\(B\\+b\\)\\*h/2\\}", ((B + b) * h) / 2.0, 11, { VERDE });
    cout << t << "\n";
}
