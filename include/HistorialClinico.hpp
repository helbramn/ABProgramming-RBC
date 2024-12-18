#ifndef HISTORIALCLINICO_HPP
#define HISTORIALCLINICO_HPP

#include <vector>
#include <string>

class HistorialClinico {
private:
    std::vector<std::string> diagnosticos;

public:
    void agregarDiagnostico(const std::string& diagnostico);
    void consultarHistorial() const;
};

#endif