#include "rectangulo.h"
#include "utils.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo(double a, double b) : a(a), b(b) {}

void Rectangulo::dibujar() {
    string t = leerArchivo("rectangulo.txt");
    colorearPalabra(t, "Rectángulo", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{b\\+a\\}", b + a, 5, { AZUL });
    t = sustitucionRegex(t, "\\{2\\*\\(b\\+a\\)\\}", 2 * (b + a), 9, { VERDE });
    t = sustitucionRegex(t, "\\{bb\\*aa\\}", b * a, 7, { VERDE });
    cout << t << "\n";
}
