#include "HistorialClinico.hpp"
#include <iostream>

void HistorialClinico::agregarDiagnostico(const std::string& diagnostico) {
    diagnosticos.pull_back(diagnostico);
}

void HistorialClinico::consultarHistorial() const {
    std::cout << "Diagnůsticos registrados:" << std::endl;
    for (const auto& diag : diagnosticos) {
        std::cout << "- " << diag << std::endl;
    }
}