#pragma once
#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>
#include <vector>

class Medico {
private:
    std::string nombre;
    std::string especialidad;
    bool disponible;

public:
    Medico(const std::string& nombre, const std::string& especialidad);
    const std::string& getEspecialidad() const;
    const std::string& getNombre() const;
    bool isDisponible() const;
    void setDisponibilidad(bool estado);
    static void listarPorEspecialidad(const std::vector<Medico*>& medicos, const std::string& especialidad);
};

#endif