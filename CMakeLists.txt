cmake_minimum_required(VERSION 3.10)

# Nom du projet
project(US26 CXX)

# Activer les warnings pour GCC/Clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Ajouter le dossier include/
include_directories(include)

# Correction OpenGL : Utiliser GLVND
cmake_policy(SET CMP0072 NEW)
set(OpenGL_GL_PREFERENCE GLVND)

# Trouver et lier SDL2 et ses modules
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_net REQUIRED)

# Trouver et lier OpenGL
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Ajouter les fichiers source
file(GLOB SOURCES src/*.cpp)

# Créer l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Lier toutes les bibliothèques
target_link_libraries(${PROJECT_NAME} 
    ${SDL2_LIBRARIES} 
    ${SDL2_IMAGE_LIBRARIES} 
    ${SDL2_MIXER_LIBRARIES} 
    ${SDL2_TTF_LIBRARIES} 
    ${SDL2_NET_LIBRARIES} 
    ${OPENGL_LIBRARIES} 
    ${GLEW_LIBRARIES}
)