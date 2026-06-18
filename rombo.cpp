#include "rombo.h"
#include "utils.h"
#include <iostream>
using namespace std;

Rombo::Rombo(double a, double d, double D) : a(a), d(d), D(D) {}

void Rombo::dibujar() {
    string t = leerArchivo("rombo.txt");
    colorearPalabra(t, "Rombo", AMARILLO_CLARO);
    colorearPalabra(t, "Desarrollo", VERDE);
    t = sustitucionRegex(t, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{ddd\\}", d, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{DDD\\}", D, 5, { MORADO, AZUL });
    t = sustitucionRegex(t, "\\{4\\*a\\}", 4 * a, 5, { VERDE });
    t = sustitucionRegex(t, "\\{D\\*d/2\\}", (D * d) / 2.0, 7, { VERDE });
    cout << t << "\n";
}
