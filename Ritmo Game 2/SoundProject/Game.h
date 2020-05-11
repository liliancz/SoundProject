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

	void text(SDL_Texture* font_texture, int score, int multiply);
	void print_text(SDL_Texture* font_texture, char text[100], float text_x, float text_y, int random_text_size);
	void Init(const char* title, int xpos, int ypos, int width, int height);
	void handleEvents();
	void update();
	void spawnobjectA();
	void spawnobjectS();
	void render();
	void clean();
	//void drawRect();
	int timetospawn = 0;

	bool Running(){ return isRunning; };

	bool randombool();

	//SDL_Texture* Texture;
	//SDL_Rect dRect;
	int spawncounter = 0;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	bool isRunning;
};

#endif // !_GAME_H

