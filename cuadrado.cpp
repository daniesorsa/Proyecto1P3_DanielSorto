#include "cuadrado.h"
#include "funciones.h"
#include <iostream>
using namespace std;

Cuadrado::Cuadrado(double a) : a(a) {}

void Cuadrado::dibujar() {
    string texto = leerArchivo("cuadrado.txt");
    colorearPalabra(texto, "Cuadrado", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{4\\*a\\}", 4 * a, 5, { VERDE });
    texto = sustitucionRegex(texto, "\\{aa\\^2\\}", a * a, 6, { VERDE });
    cout << texto << "\n";
}
