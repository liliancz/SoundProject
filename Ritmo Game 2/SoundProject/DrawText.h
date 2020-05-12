#pragma once

#ifndef _DRAWTEXT_H
#define _DRAWTEXT_H

#include "SDL2_ttf-2.0.15/include/SDL_ttf.h"
#include "SDL2-2.0.12/include/SDL.h"

class DrawText
{
public:
	DrawText(SDL_Renderer* ren, const char* TEXT, int xpos, int ypos, int size);
	~DrawText();

	void Render();
	void Update();
	void Clean();
	

private:
	TTF_Font* font;
	SDL_Color color = { 255, 255, 3 };
	SDL_Surface* text_surface;
	SDL_Texture* text_texture;
	SDL_Renderer* text_renderer;

	int texW = 0;
	int texH = 0;

	SDL_Rect dstrect;


	// example: text1 = new DrawText(renderer, "arial.ttf", "Hola", 25, { 255,255,4 }, 50, 100);
};

#endif 

