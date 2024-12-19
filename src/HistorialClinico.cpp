#include "HistorialClinico.hpp"
#include <iostream>
#include <algorithm>

void HistorialClinico::agregarDiagnostico(const std::string& diagnostico) {
    diagnosticos.push_back(diagnostico);
    std::cout << "Diagn�stico agregado: " << diagnostico << std::endl;
}
void HistorialClinico::agregarTratamiento(const std::string& tratamiento) {
    if (tratamiento.empty()) {
        std::cout << "Error: El tratamiento no puede estar vac�o." << std::endl;
        return;
    }
    tratamientos.push_back(tratamiento);
    std::cout << "Tratamiento agregado: " << tratamiento << std::endl;

}
void HistorialClinico::agregarReceta(const std::string& receta) {
    if (receta.empty()) {
        std::cout << "Error: La receta no puede estar vac�a." << std::endl;
        return;
    }
    recetas.push_back(receta);
    std::cout << "Receta agregada: " << receta << std::endl;
}
void HistorialClinico::agregarCirugia(const std::string& cirugia) {
    if (cirugia.empty()) {
        std::cout << "Error: La cirug�a no puede estar vac�a." << std::endl;
        return;
    }
    cirugias.push_back(cirugia);
    std::cout << "Cirug�a agregada: " << cirugia << std::endl;
}
void HistorialClinico::consultarHistorial() const {
   std::cout << "=== Historial Cl�nico ===" << std::endl;
   std::cout << "Diagn�sticos:" << std::endl;
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
   std::cout << "Cirug�as:" << std::endl;
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