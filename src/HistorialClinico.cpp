#include "HistorialClinico.hpp"
#include <iostream>
#include <algorithm>

void HistorialClinico::agregarDiagnostico(const std::string& diagnostico) {
    diagnosticos.push_back(diagnostico);
    std::cout << "Diagnostico agregado: " << diagnostico << std::endl;
}
void HistorialClinico::agregarTratamiento(const std::string& tratamiento) {
    if (tratamiento.empty()) {
        std::cout << "Error: El tratamiento no puede estar vacio." << std::endl;
        return;
    }
    tratamientos.push_back(tratamiento);
    std::cout << "Tratamiento agregado: " << tratamiento << std::endl;

}
void HistorialClinico::agregarReceta(const std::string& receta) {
    if (receta.empty()) {
        std::cout << "Error: La receta no puede estar vacia." << std::endl;
        return;
    }
    recetas.push_back(receta);
    std::cout << "Receta agregada: " << receta << std::endl;
}
void HistorialClinico::agregarCirugia(const std::string& cirugia) {
    if (cirugia.empty()) {
        std::cout << "Error: La cirugia no puede estar vacia." << std::endl;
        return;
    }
    cirugias.push_back(cirugia);
    std::cout << "Cirugia agregada: " << cirugia << std::endl;
}
void HistorialClinico::consultarHistorial() const {
   std::cout << "=== Historial Cl�nico ===" << std::endl;
   std::cout << "Diagnosticos:" << std::endl;
    for (const auto& diag : diagnosticos) {
        std::cout << "- " << diag << std::endl;
    }
   std::cout << "Tratamientos:" << std::endl;
    for (const auto& trat : tratamientos) {
        std::cout << "- " << trat << std::endl;
    }
   std::cout << "Recetas:" << std::endl;
    for (const auto& rec : recetas) {
        std::cout << "- " << rec << std::endl;
    }
   std::cout << "Cirugias:" << std::endl;
    for (const auto& cir : cirugias) {
        std::cout << "- " << cir << std::endl;
    }
}

void HistorialClinico::buscarPorTipo(const std::string& tipo) const {
    std::cout << "Resultados para: " << tipo << std::endl;
    const auto& lista = (tipo == "diagnostico") ? diagnosticos :
        (tipo == "tratamiento") ? tratamientos :
        (tipo == "receta") ? recetas : cirugias;
    for (const auto& item : lista) {
        std::cout << "- " << item << std::endl;
    }
}