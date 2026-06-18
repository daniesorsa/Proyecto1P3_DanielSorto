#include "cometa.h"
#include "utils.h"
#include <iostream>
using namespace std;

Cometa::Cometa(double a, double b, double d, double D) : a(a), b(b), d(d), D(D) {}

void Cometa::dibujar() {
    string t = leerArchivo("cometa.txt");
    colorearPalabra(t, "Cometa", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{ddd\\}", d, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{DDD\\}", D, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{b\\+a\\}", b + a, 5, { AZUL });
    t = sustitucionRegex(t, "\\{2\\*\\(b\\+a\\)\\}", 2 * (b + a), 9, { VERDE });
    t = sustitucionRegex(t, "\\{D\\*d/2\\}", (D * d) / 2.0, 7, { VERDE });
    cout << t << "\n";
}
