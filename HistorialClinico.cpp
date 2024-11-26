#include "HistorialClinico.h"
#include <iostream> 

void HistorialClinico::agregarRegistro(const std::string& registro) {
    registros.push_back(registro);
}

void HistorialClinico::mostrarRegistros() const {
    std::cout << "Registros de Historial Clínico:" << std::endl;
    for (const auto& registro : registros) {
        std::cout << registro << std::endl;
    }
}