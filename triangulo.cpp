#include "triangulo.h"
#include "funciones.h"

Triangulo::Triangulo(double a, double b, double c, double h) : a(a), b(b), c(c), h(h) {}

void Triangulo::dibujar() {
    string texto = leerArchivo("triangulo.txt");
    colorearPalabra(texto, "Triángulo", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{ccc\\}", c, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{hhh\\}", h, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{a\\+b\\+c\\}", a + b + c, 7, { VERDE });
    texto = sustitucionRegex(texto, "\\{bb\\*hh/2\\}", (b * h) / 2.0, 9, { VERDE });
    cout << texto << "\n";
}
