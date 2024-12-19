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

public:
    void agregarDiagnostico(const std::string& diagnostico);
    void agregarTratamiento(const std::string& tratamiento); 
    void agregarReceta(const std::string& receta); 
    void agregarCirugia(const std::string& cirugia); 
    void consultarHistorial() const;
    void buscarPorTipo(const std::string& tipo) const; 
};

#endif