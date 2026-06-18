#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <windows.h>
#include "triangulo.h"
#include "paralelogramo.h"
#include "rectangulo.h"
#include "cuadrado.h"
#include "rombo.h"
#include "cometa.h"
#include "trapecio.h"
#include "circulo.h"

using namespace std;

void mostrarAyuda() {
    cout << "Uso: " << AMARILLO << "Projecto_1.exe" << RESET << " ACCIÓN " << FONDO_MORADO << "[VARIABLES]" << RESET << "\n";
    cout << "  calculos de perímetro y área de Figuras Planas.\n";
    cout << "       Donde:\n";
    cout << "          ACCIÓN:\n";
    cout << "              " << AMARILLO << "ayuda"         << RESET << "           | Información sobre el uso del programa.\n\n";
    cout << "              " << AMARILLO << "triángulo"     << RESET << "       | VARIABLES: " << FONDO_MORADO << "a b c h"    << RESET << "\n";
    cout << "              " << AMARILLO << "paralelogramo" << RESET << "   | VARIABLES: " << FONDO_MORADO << "a b h"         << RESET << "\n";
    cout << "              " << AMARILLO << "rectángulo"    << RESET << "      | VARIABLES: " << FONDO_MORADO << "a b"         << RESET << "\n";
    cout << "              " << AMARILLO << "cuadrado"      << RESET << "        | VARIABLES: " << FONDO_MORADO << "a"         << RESET << "\n";
    cout << "              " << AMARILLO << "rombo"         << RESET << "           | VARIABLES: " << FONDO_MORADO << "a d D"   << RESET << "\n";
    cout << "              " << AMARILLO << "cometa"        << RESET << "          | VARIABLES: " << FONDO_MORADO << "a b d D"  << RESET << "\n";
    cout << "              " << AMARILLO << "trapecio"      << RESET << "        | VARIABLES: " << FONDO_MORADO << "a b c h B" << RESET << "\n";
    cout << "              " << AMARILLO << "circulo"       << RESET << "         | VARIABLES: " << FONDO_MORADO << "r"        << RESET << "\n";
}

string aMinuscula(string texto) {
    string res = "";
    for (int i = 0; i < (int)texto.length(); ++i) {
        if (texto[i] >= 'A' && texto[i] <= 'Z') {
            res += tolower(texto[i]);
        } else if ((unsigned char)texto[i] == 0xC3 && i + 1 < (int)texto.length()) {
            unsigned char sig = texto[++i];
            if      (sig == 0x81) res += "\xc3\xa1";
            else if (sig == 0x89) res += "\xc3\xa9";
            else if (sig == 0x8D) res += "\xc3\xad";
            else if (sig == 0x93) res += "\xc3\xb3";
            else if (sig == 0x9A) res += "\xc3\xba";
            else                  res += texto[i - 1];
        } else {
            res += texto[i];
        }
    }
    return res;
}

OpcionFigura obtenerOpcion(const string& accion) {
    string acc = aMinuscula(accion);
    if (acc == "ayuda")                              return AYUDA;
    if (acc == "triángulo"  || acc == "triangulo")  return TRIANGULO;
    if (acc == "paralelogramo")                      return PARALELOGRAMO;
    if (acc == "rectángulo" || acc == "rectangulo") return RECTANGULO;
    if (acc == "cuadrado")                           return CUADRADO;
    if (acc == "rombo")                              return ROMBO;
    if (acc == "cometa")                             return COMETA;
    if (acc == "trapecio")                           return TRAPECIO;
    if (acc == "circulo"    || acc == "círculo")     return CIRCULO;
    return INVALIDO;
}

string leerArchivo(const string& nombre) {
    ifstream archivo(nombre);
    if (!archivo.is_open()) return "Error: No se pudo abrir el archivo " + nombre + "\n";
    ostringstream ss;
    ss << archivo.rdbuf();
    return ss.str();
}

string formatoDeNumeros(double val, int ancho, const string& color) {
    ostringstream out;
    out << val;
    string s = out.str();
    int izq = 0, der = 0;
    if ((int)s.length() < ancho) {
        int espacios = ancho - (int)s.length();
        izq = espacios / 2;
        der = espacios - izq;
    }
    return string(izq, ' ') + color + s + RESET + string(der, ' ');
}

string sustitucionRegex(string texto, const string& patron, double valor, int ancho, const vector<string>& colores) {
    regex e(patron);
    smatch m;
    string res = "";
    int indice = 0;
    string::const_iterator inicio(texto.cbegin());
    while (regex_search(inicio, texto.cend(), m, e)) {
        res += m.prefix();
        string color = (indice < (int)colores.size()) ? colores[indice] : colores.back();
        res += formatoDeNumeros(valor, ancho, color);
        inicio = m.suffix().first;
        indice++;
    }
    res += string(inicio, texto.cend());
    return res;
}

void colorearPalabra(string& texto, const string& palabra, const string& color) {
    size_t posicion = texto.find(palabra);
    texto.replace(posicion, palabra.length(), color + palabra + RESET);
}

void dibujarFigura(OpcionFigura opcion, const vector<string>& args) {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int numVars = (int)args.size() - 2;
    try {
        switch (opcion) {
            case TRIANGULO:     if (numVars == 4) Triangulo(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])).dibujar();                              else mostrarAyuda(); break;
            case PARALELOGRAMO: if (numVars == 3) Paralelogramo(stod(args[2]), stod(args[3]), stod(args[4])).dibujar();                                         else mostrarAyuda(); break;
            case RECTANGULO:    if (numVars == 2) Rectangulo(stod(args[2]), stod(args[3])).dibujar();                                                           else mostrarAyuda(); break;
            case CUADRADO:      if (numVars == 1) Cuadrado(stod(args[2])).dibujar();                                                                            else mostrarAyuda(); break;
            case ROMBO:         if (numVars == 3) Rombo(stod(args[2]), stod(args[3]), stod(args[4])).dibujar();                                                 else mostrarAyuda(); break;
            case COMETA:        if (numVars == 4) Cometa(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])).dibujar();                                 else mostrarAyuda(); break;
            case TRAPECIO:      if (numVars == 5) Trapecio(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5]), stod(args[6])).dibujar();                else mostrarAyuda(); break;
            case CIRCULO:       if (numVars == 1) Circulo(stod(args[2])).dibujar();                                                                             else mostrarAyuda(); break;
            default:            mostrarAyuda(); break;
        }
    } catch (...) {
        cout << AMARILLO << "Error: Por favor ingrese valores numéricos válidos.\n\n" << RESET;
        mostrarAyuda();
    }
}
