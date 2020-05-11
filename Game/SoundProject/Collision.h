#pragma once
#include "SDL2-2.0.12/include/SDL.h"

class Collision
{
public:
	static bool AABB(const SDL_Rect& A, const SDL_Rect& B);
};

