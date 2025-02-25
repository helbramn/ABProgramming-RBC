#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include "HistorialClinico.hpp"

class Paciente {
private:
    std::string Pnombre;
    std::string dni;
    std::string id;
    std::string fechaIngreso;
    HistorialClinico historial;

public:
    Paciente(const std::string& Pnombre, const std::string& dni, const std::string& fechaIngreso);
    const std::string& getID() const;
    const std::string& getDNI() const;
    const std::string& getNombre() const;
    const std::string& getFechaIngreso() const;
    const HistorialClinico& getHistorial() const;
    HistorialClinico& getHistorial();
    void modificarDatos();
    static bool validarDNI(const std::string& dni);  
    bool buscarPaciente(const std::string& criterio);


    void registrarDiagnostico(const std::string& diagnostico);
    void consultarHistorial() const;
};

#endif

