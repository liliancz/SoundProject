#include "SDL2-2.0.12/include/SDL.h"
#include "SDL2_image-2.0.3/include/SDL_image.h"
#include <iostream>
#include "Game.h"
#include <time.h>
#include "SDL2_ttf-2.0.15/include/SDL_ttf.h"
#include "Constants.h"
#include "Object.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	
	const int FPS = 60;
	const int frameDelay = 600 / FPS;
	Uint32 frameStart;
	int frameTime;
	float arrowTimer = 0;
	float arrowInterval = 50;
	bool start = false;

	game = new Game();
	game->Init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);
	Object* Inicio = new Object("assets/inicio.png", game->renderer, 0, 0);
	Inicio->Fullscreen();
	SDL_RenderClear(game->renderer);
	Inicio->Render();
	SDL_RenderPresent(game->renderer);
	
	while (!start)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			SDL_Quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				start = true;
				game->play();
				break;
			}
		}
	}


	float t = 2;
	while (game->Running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		//game->spawnobject();
		bool spawn = false;
		

		if (arrowTimer > arrowInterval)
		{
			arrowTimer = 0;
			spawn = game->randombool();
			if (spawn == true)
				game->spawnobjectA();
			spawn = game->randombool();
			if (spawn == true)
				game->spawnobjectS();
			spawn = game->randombool();
			if (spawn == true)
				game->spawnobjectK();
			spawn = game->randombool();
			if (spawn == true)
				game->spawnobjectL();
		}
		
		arrowTimer++;

		game->update(t);
		game->render();

		
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
			
		}
		
	

		
	}	

	game->clean();
	
	return 0;
}