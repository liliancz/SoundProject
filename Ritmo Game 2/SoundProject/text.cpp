#include "SDL2-2.0.12/include/SDL.h"
#include "SDL2_ttf-2.0.15/include/SDL_ttf.h"
#include "DrawText.h"

DrawText* text1;
int main(int argc, char** argv)
{
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    text1->Init();

    SDL_Window* window = SDL_CreateWindow("SDL_ttf in SDL2",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
        480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    
    text1 = new DrawText(renderer, "arial.ttf", "Hola", 25, { 255,255,4 }, 50, 100);


    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_QUIT:
            quit = true;
            break;
        }

        text1->Render();
    }

    text1->Clean();
    SDL_DestroyWindow(window);
   
    SDL_Quit();

    return 0;
}