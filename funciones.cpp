#include "funciones.h"
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
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Uso: " << AMARILLO << "Figuras_Planas.exe" << RESET << " ACCIÓN " << FONDO_MORADO << "[VARIABLES]" << RESET << "\n";
    cout << "       Calculos de perímetro y área de Figuras Planas.\n";
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
    for (int indice = 0; indice < (int)texto.length(); ++indice) {
        if (texto[indice] >= 'A' && texto[indice] <= 'Z')
            res += tolower(texto[indice]);
        else if ((unsigned char)texto[indice] == 195 && indice + 1 < texto.length()) {
            unsigned char siguiente = texto[indice + 1];
            if(siguiente == 129)
                siguiente = 161; // á
            else if (siguiente == 137)  
                siguiente = 169; // é
            else if (siguiente == 141)  
                siguiente = 173; // í
            else if (siguiente == 147)
                siguiente = 179; // ó
            else if (siguiente == 154)
                siguiente = 186; // ú
            res += texto[indice];
            res += siguiente;
            indice++;
        } else
            res += texto[indice];
    }
    return res;
}

OpcionFigura obtenerOpcion(const string& accion) {
    string acc = aMinuscula(accion);
    if (acc == "ayuda")
        return AYUDA;
    else if (acc == "triángulo"  || acc == "triangulo")
        return TRIANGULO;
    else if (acc == "paralelogramo")
        return PARALELOGRAMO;
    else if (acc == "rectángulo" || acc == "rectangulo")
        return RECTANGULO;
    else if (acc == "cuadrado")
        return CUADRADO;
    else if (acc == "rombo")
        return ROMBO;
    else if (acc == "cometa")
        return COMETA;
    else if (acc == "trapecio")
        return TRAPECIO;
    else if (acc == "circulo"    || acc == "círculo")
        return CIRCULO;
    return INVALIDO;
}

string leerArchivo(const string& nombreArchivo) {
    ifstream archivo("../../" + nombreArchivo);
    if (!archivo.is_open())
        return "Error, no se pudo abrir el archivo " + nombreArchivo + "\n";
    stringstream buffer;
    buffer << archivo.rdbuf();
    archivo.close();
    return buffer.str();
}

string formatoDeNumeros(double valorActual, int ancho, const string& color) {
    stringstream out;
    out << valorActual;
    string valorActualStr = out.str();
    int espaciosIzqquierda = 0;
    int espaciosDerecha = 0;
    if (valorActualStr.length() < ancho) {
        int totalEspacios = ancho - valorActualStr.length();
        espaciosIzqquierda = totalEspacios / 2;
        espaciosDerecha = totalEspacios - espaciosIzqquierda;
    }
    return string(espaciosIzqquierda, ' ') + color + valorActualStr + RESET + string(espaciosDerecha, ' ');
}

string sustitucionRegex(string texto, const string& patron, double valorActual, int ancho, const vector<string>& colores) {
    regex expresion(patron);
    smatch coincidencia; // pre-expresion, expresion, postexpresion
    string res = "";
    int indiceColor = 0;
    string::const_iterator inicio(texto.cbegin());
    while (regex_search(inicio, texto.cend(), coincidencia, expresion)) {
        res += coincidencia.prefix();
        string colorActual = (indiceColor < colores.size()) ? colores[indiceColor] : colores.back();
        res += formatoDeNumeros(valorActual, ancho, colorActual);
        inicio = coincidencia.suffix().first;
        indiceColor++;
    }
    res += string(inicio, texto.cend());
    return res;
}

void colorearPalabra(string& texto, const string& palabra, const string& color) {
    int posicion = texto.find(palabra);
    texto.replace(posicion, palabra.length(), color + palabra + RESET);
}

void dibujarFigura(OpcionFigura opcion, const vector<string>& args) {
    for (int indice = 0; indice < args.size(); indice++) {
        if (args.at(indice).size() > 5) {
            cout << "\nNumero muy grande, ingrese numeros menores a 5 digitos.\n";
            mostrarAyuda();
            return;
        }
    }
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int numVars = args.size() - 2;
    try {
        switch (opcion) {
            case TRIANGULO:
                if (numVars == 4)
                    Triangulo(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])).dibujar();
                else mostrarAyuda();
                break;
            case PARALELOGRAMO:
                if (numVars == 3)
                    Paralelogramo(stod(args[2]), stod(args[3]), stod(args[4])).dibujar();
                else mostrarAyuda();
                break;
            case RECTANGULO:
                if (numVars == 2)
                    Rectangulo(stod(args[2]), stod(args[3])).dibujar();
                else mostrarAyuda();
                break;
            case CUADRADO:
                if (numVars == 1)
                    Cuadrado(stod(args[2])).dibujar();
                else mostrarAyuda();
                break;
            case ROMBO:
                if (numVars == 3)
                    Rombo(stod(args[2]), stod(args[3]), stod(args[4])).dibujar();
                else mostrarAyuda();
                break;
            case COMETA:
                if (numVars == 4)
                    Cometa(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5])).dibujar();
                else mostrarAyuda();
                break;
            case TRAPECIO:
                if (numVars == 5)
                    Trapecio(stod(args[2]), stod(args[3]), stod(args[4]), stod(args[5]), stod(args[6])).dibujar();
                else mostrarAyuda();
                break;
            case CIRCULO:
                if (numVars == 1)
                    Circulo(stod(args[2])).dibujar();
                else mostrarAyuda();
                break;
            default:
                cout << "\nNombre de figura o archivo incorrecto\n";
                mostrarAyuda();
                break;
        }
    } catch (...) {
        cout << AMARILLO << "Error, ingrese un numéro válido.\n\n" << RESET;
        mostrarAyuda();
    }
}
