#include "Object.h"
#include "TextureM.h"
#include "Constants.h"

Object::Object(const char* texturesheet, SDL_Renderer* ren, int x, int y) {

	renderer = ren;
	objTexture =TextureM::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
};
Object::~Object() {
};

void Object::uniquepos(int x, int y) {

	dRect.x = x;
	dRect.y = y;
	dRect.h = 64;
	dRect.w = 64;
};

void Object::resetpos(int x, int y) {
	xpos = x;
	ypos = y;
};

void Object::Fullscreen() {
	dRect.x = 0;
	dRect.y = 0;
	dRect.h = SCREEN_HEIGHT;
	dRect.w = SCREEN_WIDTH;
};

void Object::Update(float t) {
	
	ypos++;
	dRect.x = xpos;
	dRect.h = 64;
	dRect.w = 64;
	dRect.y = ypos*t;
};

void Object::Render() {
	SDL_RenderCopy(renderer, objTexture, NULL, &dRect);
};


