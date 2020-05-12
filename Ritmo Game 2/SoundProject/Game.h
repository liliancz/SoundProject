#pragma once
#ifndef _GAME_H
#define _GAME_H
#include "SDL2-2.0.12/include/SDL.h"
#include "SDL_image.h"
#include <stdio.h>

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void update(float t);
	void spawnobjectA();
	void spawnobjectS();
	void spawnobjectK();
	void spawnobjectL();
	void render();
	void clean();
	//void drawRect();
	
	bool Running(){ return isRunning; };

	bool randombool();

	//SDL_Texture* Texture;
	//SDL_Rect dRect;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;
};

#endif // !_GAME_H

