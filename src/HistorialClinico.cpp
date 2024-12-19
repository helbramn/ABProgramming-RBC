#include "HistorialClinico.hpp"
#include <iostream>

void HistorialClinico::agregarDiagnostico(const std::string& diagnostico) {
    diagnosticos.push_back(diagnostico);
}
void HistorialClinico::agregarTratamiento(const std::string& tratamiento) {
    tratamientos.push_back(tratamiento);
}
void HistorialClinico::agregarReceta(const std::string& receta) {
    recetas.push_back(receta);
}
void HistorialClinico::agregarCirugia(const std::string& cirugia) {
    cirugias.push_back(cirugia);
}
void HistorialClinico::consultarHistorial() const {
    std::cout << "Diagnosticos registrados:" << std::endl;
    for (const auto& diag : diagnosticos) {
        std::cout << "- " << diag << std::endl;
    }
}