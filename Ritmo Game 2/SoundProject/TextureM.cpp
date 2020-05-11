#include "TextureM.h"

SDL_Texture* TextureM::LoadTexture(const char* filename, SDL_Renderer* ren) {
	SDL_Surface* tmpSurface = IMG_Load(filename);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}

