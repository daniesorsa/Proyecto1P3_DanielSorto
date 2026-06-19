#include "rombo.h"
#include "funciones.h"

Rombo::Rombo(double a, double d, double D) : a(a), d(d), D(D) {}

void Rombo::dibujar() {
    std::string texto = leerArchivo("rombo.txt");
    colorearPalabra(texto, "Rombo", AMARILLO_CLARO);
    colorearPalabra(texto, "Desarrollo", VERDE);
    texto = sustitucionRegex(texto, "\\{aaa\\}", a, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{ddd\\}", d, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{DDD\\}", D, 5, { MORADO, AZUL });
    texto = sustitucionRegex(texto, "\\{4\\*a\\}", 4 * a, 5, { VERDE });
    texto = sustitucionRegex(texto, "\\{D\\*d/2\\}", (D * d) / 2.0, 7, { VERDE });
    std::cout << texto << "\n";
}
