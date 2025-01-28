cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(US26 CXX)

# Activer les warnings pour GCC/Clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Ajouter le dossier include/
include_directories(include)

# Trouver SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Ajouter les fichiers source
file(GLOB SOURCES src/*.cpp)

# Créer l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier SDL2 à l'exécutable
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})