cmake_minimum_required(VERSION 3.5)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options d'optimisation corrigées
set(CMAKE_CXX_FLAGS "-O0") # Défaut pour tous les builds
set(CMAKE_CXX_FLAGS_DEBUG "-O0") # Pas d'optimisation, favorise le débogage
set(CMAKE_CXX_FLAGS_RELEASE "-O2") # Optimisation de niveau 2 pour les builds Release

add_definitions(-DUNICODE -D_UNICODE)

project(mutantur)

include_directories(src)

add_library(
    ${PROJECT_NAME}
    src/utils.h
    src/utils.cpp
    src/mutantur.h
    src/mutantur.cpp
)

add_subdirectory(tests)