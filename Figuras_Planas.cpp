#include <vector>
#include <string>
#include "funciones.h"
using namespace std;
int main(int argc, char* argv[]) {
    vector<string> args(argv, argv + argc);
    OpcionFigura opcion = (args.size() > 1) ? obtenerOpcion(args[1]) : INVALIDO;
    dibujarFigura(opcion, args);
    return 0;
}