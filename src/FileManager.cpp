#include "FileManager.hpp"
#include <iostream>

const std::string FileManager::RUTA_BASE = "../data/";

void FileManager::crearCarpeta() {
    if (!std::filesystem::exists(RUTA_BASE)) {
        std::filesystem::create_directory(RUTA_BASE);
    }
}

std::string FileManager::obtenerRutaArchivo(const std::string& nombreArchivo) {
    return RUTA_BASE + nombreArchivo; 
}
