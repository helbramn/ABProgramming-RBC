#ifndef HISTORIALCLINICO_HPP
#define HISTORIALCLINICO_HPP

#include <vector>
#include <string>

class HistorialClinico {
private:
    std::vector<std::string> diagnosticos;
    std::vector<std::string> tratamientos;
    std::vector<std::string> recetas;
    std::vector<std::string> cirugias;

    std::string vectorToCSV(const std::vector<std::string>& vec) const;
    std::vector<std::string> csvToVector(const std::string& csv) const;

public:
    void agregarDiagnostico(const std::string& diagnostico);
    void agregarTratamiento(const std::string& tratamiento); 
    void agregarReceta(const std::string& receta); 
    void agregarCirugia(const std::string& cirugia); 
    void consultarHistorial() const;
    void procesarDiagnosticos(const std::string& csv);
    void procesarTratamientos(const std::string& csv);
    void procesarRecetas(const std::string& csv);
    void procesarCirugias(const std::string& csv);

    std::string getDiagnosticosCSV() const;
    std::string getTratamientosCSV() const;
    std::string getRecetasCSV() const;
    std::string getCirugiasCSV() const;

    std::string serializar() const;
    void deserializar(const std::string& data);
};

#endif