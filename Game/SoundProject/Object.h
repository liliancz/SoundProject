#pragma once
#ifndef _OBJECT_H
#define _OBJECT_H
#include "Game.h"

class Object
{
public:
	Object(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~Object();
	void Update();
	void uniquepos(int x, int y);
	void resetpos(int x, int y);
	void Render();
	bool activate = false;
	SDL_Rect dRect;
private:
	
	SDL_Texture* objTexture;
	SDL_Renderer* renderer;

	int xpos;
	int ypos;


	

};

#endif // !_OBJECT_H

