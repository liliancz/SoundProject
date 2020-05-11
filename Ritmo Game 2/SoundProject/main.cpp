#include "SDL2-2.0.12/include/SDL.h"
#include "SDL2_image-2.0.3/include/SDL_image.h"
#include <iostream>
#include "Game.h"
#include <time.h>
#include "SDL2_ttf-2.0.15/include/SDL_ttf.h"


const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 500;

Game* game = nullptr;

int main(int argc, char* argv[]) {
	
	const int FPS = 60;
	const int frameDelay = 500 / FPS;
	Uint32 frameStart;
	int frameTime;
	int arrowTimer = 0;
	int arrowInterval = 100;

	


	game = new Game();
	game->Init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT);
	

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
		}
		arrowTimer++;
		game->update();
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