#include "cometa.h"
#include "funciones.h"
#include <iostream>
using namespace std;

Cometa::Cometa(double a, double b, double d, double D) : a(a), b(b), d(d), D(D) {}

void Cometa::dibujar() {
    string texto = leerArchivo("cometa.txt");
    colorearPalabra(texto, "Cometa", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{ddd\\}", d, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{DDD\\}", D, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{b\\+a\\}", b + a, 5, { AZUL });
    texto = sustitucionRegex(texto, "\\{2\\*\\(b\\+a\\)\\}", 2 * (b + a), 9, { VERDE });
    texto = sustitucionRegex(texto, "\\{D\\*d/2\\}", (D * d) / 2.0, 7, { VERDE });
    cout << texto << "\n";
}
