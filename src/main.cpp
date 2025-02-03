#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

// Largeur et hauteur de la fenêtre
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Initialiser SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur SDL_Init: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Configurer SDL pour utiliser OpenGL
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Créer une fenêtre SDL avec support OpenGL
    SDL_Window* window = SDL_CreateWindow(
        "Test SDL2 + OpenGL + GLEW",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Erreur SDL_CreateWindow: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Créer un contexte OpenGL
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "Erreur SDL_GL_CreateContext: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialiser GLEW (nécessaire après la création du contexte OpenGL)
    GLenum glewStatus = glewInit();
    if (glewStatus != GLEW_OK) {
        std::cerr << "Erreur GLEW: " << glewGetErrorString(glewStatus) << std::endl;
        SDL_GL_DeleteContext(glContext);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Afficher la version OpenGL
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    // Définir la couleur de fond (noir)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Boucle principale (affiche la fenêtre pendant 3 secondes)
    bool running = true;
    Uint32 startTime = SDL_GetTicks();
    while (running) {
        // Gestion des événements SDL
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Effacer l'écran avec la couleur de fond
        glClear(GL_COLOR_BUFFER_BIT);

        // Rafraîchir l'affichage
        SDL_GL_SwapWindow(window);

        // Quitter après 3 secondes
        if (SDL_GetTicks() - startTime > 3000) {
            running = false;
        }
    }

    // Nettoyage
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}