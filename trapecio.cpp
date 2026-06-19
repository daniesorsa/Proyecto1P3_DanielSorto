#include "trapecio.h"
#include "funciones.h"

Trapecio::Trapecio(double a, double b, double c, double h, double B) : a(a), b(b), c(c), h(h), B(B) {}

void Trapecio::dibujar() {
    string texto = leerArchivo("trapecio.txt");
    colorearPalabra(texto, "Trapecio", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{ccc\\}", c, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{hhh\\}", h, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{BBB\\}", B, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{B\\+b\\+a\\+c\\}", B + b + a + c, 9, { VERDE });
    texto = sustitucionRegex(texto, "\\{\\(B\\+b\\)\\*h/2\\}", ((B + b) * h) / 2.0, 11, { VERDE });
    cout << texto << "\n";
}
