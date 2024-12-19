#include "HistorialClinico.hpp"
#include <iostream>

void HistorialClinico::agregarDiagnostico(const std::string& diagnostico) {
    diagnosticos.push_back(diagnostico);
}

void HistorialClinico::consultarHistorial() const {
    std::cout << "Diagnosticos registrados:" << std::endl;
    for (const auto& diag : diagnosticos) {
        std::cout << "- " << diag << std::endl;
    }
}