#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur SDL_Init: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Erreur SDL_CreateWindow: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Delay(3000); // Garde la fenêtre ouverte 3 secondes

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}