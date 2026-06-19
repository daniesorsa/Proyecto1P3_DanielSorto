#include "rectangulo.h"
#include "funciones.h"

Rectangulo::Rectangulo(double a, double b) : a(a), b(b) {}

void Rectangulo::dibujar() {
    std::string texto = leerArchivo("rectangulo.txt");
    colorearPalabra(texto, "Rectángulo", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{bbb\\}", b, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{b\\+a\\}", b + a, 5, { AZUL });
    texto = sustitucionRegex(texto, "\\{2\\*\\(b\\+a\\)\\}", 2 * (b + a), 9, { VERDE });
    texto = sustitucionRegex(texto, "\\{bb\\*aa\\}", b * a, 7, { VERDE });
    std::cout << texto << "\n";
}
