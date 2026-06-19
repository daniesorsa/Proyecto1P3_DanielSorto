#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

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

string aMinuscula(string texto);
OpcionFigura obtenerOpcion(const string& accion);
string leerArchivo(const string& nombre);
string formatoDeNumeros(double val, int ancho, const string& color);
string sustitucionRegex(string texto, const string& patron, double valor, int ancho, const vector<string>& colores);
void colorearPalabra(string& texto, const string& palabra, const string& color);
void mostrarAyuda();
void dibujarFigura(OpcionFigura opcion, const vector<string>& args);
