#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <filesystem>

class FileManager {
public:
    static const std::string RUTA_BASE;

    static void crearCarpeta();
    static std::string obtenerRutaArchivo(const std::string& nombreArchivo);
};

#endif
