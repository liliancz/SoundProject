#include "DrawText.h"

DrawText::DrawText(SDL_Renderer* ren, const char* TEXT, int xpos, int ypos, int size) {

	text_renderer = ren;
	font = TTF_OpenFont("arial.ttf", size);
	text_surface = TTF_RenderText_Solid(font, TEXT, color);
	text_texture = SDL_CreateTextureFromSurface(text_renderer, text_surface);
	SDL_QueryTexture(text_texture, NULL, NULL, &texW, &texH);
	dstrect = { xpos, ypos, texW, texH };
	
};

DrawText::~DrawText() {};

void DrawText::Update() {};


void DrawText::Render() {
	
	SDL_RenderCopy(text_renderer, text_texture, NULL, &dstrect);
	SDL_RenderPresent(text_renderer);
};

void DrawText::Clean() {
	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text_surface);
	TTF_CloseFont(font);
	SDL_DestroyRenderer(text_renderer);
	TTF_Quit();
};