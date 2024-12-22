# CMakeList.txt: proyecto de CMake para ABProgramming RBC, incluya el origen y defina
# la lógica específica del proyecto aquí.

# Mínima versión requerida de CMake
cmake_minimum_required(VERSION 3.8)

# Nombre del proyecto
project("ABProgramming_RBC")

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Habilitar Recarga activa para MSVC (si aplica)
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Incluir directorios de encabezados
include_directories(include)

# Archivos fuente
file(GLOB SOURCES "src/*.cpp")

# Crear el ejecutable
add_executable(ABProgramming ${SOURCES})


