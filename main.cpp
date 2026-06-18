#include <vector>
#include <string>
#include "utils.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    OpcionFigura opcion = (args.size() > 1) ? obtenerOpcion(args[1]) : INVALIDO;
    dibujarFigura(opcion, args);
    return 0;
}
