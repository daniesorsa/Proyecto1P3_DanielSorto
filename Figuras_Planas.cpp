#include "funciones.h"
int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc); // copia argv a un vector de strings mediante tamaño de argv
    OpcionFigura opcion = (args.size() > 1 && args[0] == "Figuras_Plana") ? obtenerOpcion(args[1]) : INVALIDO;
    dibujarFigura(opcion, args);
}