#include "circulo.h"
#include "funciones.h"
#define PI 3.141

Circulo::Circulo(double r) : r(r) {}

void Circulo::dibujar() {
    std::string texto = leerArchivo("circulo.txt");
    colorearPalabra(texto, "Círculo", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{rrr\\}", r, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{2\\*pi\\*r\\}", 2 * PI * r, 8, { VERDE });
    texto = sustitucionRegex(texto, "\\{pi\\*r\\^2\\}", PI * (r * r), 8, { VERDE });
    std::cout << texto << "\n";
}
