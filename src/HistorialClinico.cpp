#include "HistorialClinico.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

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
   std::cout << "=== Historial Clínico ===" << std::endl;
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

std::string HistorialClinico::vectorToCSV(const std::vector<std::string>& vec) const {
    std::ostringstream oss;
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i < vec.size() - 1) {
            oss << ";";
        }
    }
    return oss.str();
}

std::vector<std::string> HistorialClinico::csvToVector(const std::string& csv) const {
    std::vector<std::string> result;
    std::istringstream iss(csv);
    std::string token;

    while (std::getline(iss, token, ';')) {
        result.push_back(token);
    }
    return result;
}

std::string HistorialClinico::serializar() const {
    return vectorToCSV(diagnosticos) + "|" + vectorToCSV(tratamientos) + "|" +
        vectorToCSV(recetas) + "|" + vectorToCSV(cirugias);
}

void HistorialClinico::deserializar(const std::string& data) {
    std::istringstream iss(data);
    std::string diag, trat, rec, cir;

    std::getline(iss, diag, '|');
    std::getline(iss, trat, '|');
    std::getline(iss, rec, '|');
    std::getline(iss, cir, '|');

    diagnosticos = csvToVector(diag);
    tratamientos = csvToVector(trat);
    recetas = csvToVector(rec);
    cirugias = csvToVector(cir);
}

std::string HistorialClinico::getDiagnosticosCSV() const {
    std::string csv;
    for (const auto& diagnostico : diagnosticos) {
        if (!csv.empty()) csv += ";"; // Separador entre diagnósticos
        csv += diagnostico;
    }
    return csv;
}

std::string HistorialClinico::getTratamientosCSV() const {
    std::string csv;
    for (const auto& tratamiento : tratamientos) {
        if (!csv.empty()) csv += ";";
        csv += tratamiento;
    }
    return csv;
}

std::string HistorialClinico::getRecetasCSV() const {
    std::string csv;
    for (const auto& receta : recetas) {
        if (!csv.empty()) csv += ";";
        csv += receta;
    }
    return csv;
}

std::string HistorialClinico::getCirugiasCSV() const {
    std::string csv;
    for (const auto& cirugia : cirugias) {
        if (!csv.empty()) csv += ";";
        csv += cirugia;
    }
    return csv;
}

