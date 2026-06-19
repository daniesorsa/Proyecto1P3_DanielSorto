#pragma once
#include <string>
#include <vector>
#include <iostream>

#define RESET          "\033[0m"
#define AMARILLO       "\033[33m"
#define FONDO_MORADO   "\033[45m"
#define AMARILLO_CLARO "\033[93m"
#define MORADO         "\033[45m\033[37m"
#define AZUL           "\033[44m\033[37m"
#define VERDE          "\033[42m\033[37m"

enum OpcionFigura {
    AYUDA,
    TRIANGULO,
    PARALELOGRAMO,
    RECTANGULO,
    CUADRADO,
    ROMBO,
    COMETA,
    TRAPECIO,
    CIRCULO,
    INVALIDO
};

std::string aMinuscula(std::string texto);
OpcionFigura obtenerOpcion(const std::string& accion);
std::string leerArchivo(const std::string& nombre);
std::string formatoDeNumeros(double val, int ancho, const std::string& color);
std::string sustitucionRegex(std::string texto, const std::string& patron, double valor, int ancho, const std::vector<std::string>& colores);
void colorearPalabra(std::string& texto, const std::string& palabra, const std::string& color);
void mostrarAyuda();
void dibujarFigura(OpcionFigura opcion, const std::vector<std::string>& args);
