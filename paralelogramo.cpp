#include "paralelogramo.h"
#include "funciones.h"
#include <iostream>
using namespace std;

Paralelogramo::Paralelogramo(double a, double b, double h) : a(a), b(b), h(h) {}

void Paralelogramo::dibujar() {
    string texto = leerArchivo("paralelogramo.txt");
    colorearPalabra(texto, "Paralelogramo", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{hhh\\}", h, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{a\\+b\\}", a + b, 5, { AZUL });
    texto = sustitucionRegex(texto, "\\{2\\*\\(a\\+b\\)\\}", 2 * (a + b), 9, { VERDE });
    texto = sustitucionRegex(texto, "\\{bb\\*hh\\}", b * h, 7, { VERDE });
    cout << texto << "\n";
}
