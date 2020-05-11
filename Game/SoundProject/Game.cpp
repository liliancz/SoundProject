#include "Game.h"
#include "Object.h"
#include "TextureM.h"
#include "Collision.h"
#include <stdlib.h>     /* srand, rand */

const int max_arrows = 100;
Object* A_KEY[max_arrows];
Object* S_KEY[max_arrows];
Object* D_KEY[max_arrows];
Object* A_marquee;
Object* S_marquee;
Object* D_marquee;

bool A_pressed = false;
bool S_pressed = false;


Game::Game() {}
Game::~Game() {}

void Game::Init(const char* title, int xpos, int ypos, int width, int height) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	for (int i = 0; i < max_arrows; i++)
	{
		A_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, 100, 0);
		S_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, 150, 0);
		D_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, 200, 0);
	}


	A_marquee = new Object("assets/Marquee_Music_Note.png", renderer, 100, 400);
	S_marquee = new Object("assets/Marquee_Music_Note.png", renderer, 150, 400);

};
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
			A_pressed = true;
			SDL_Log("A pressed");
			break;
		case SDLK_s:
			S_pressed = true;
			SDL_Log("S pressed");
			break;
		case SDLK_d:
			
			SDL_Log("d pressed");
			break;
		}


	default:
		break;
	}
};
void Game::update() {

	for (int i = 0; i < max_arrows; i++)
	{
		if (A_KEY[i]->activate == true)
		{
			A_KEY[i]->Update();
		}
		if (S_KEY[i]->activate == true)
		{
			S_KEY[i]->Update();
		}
	}
	if (A_pressed == true)
	{
		A_marquee->uniquepos(100, 400);
		for (int i = 0; i < max_arrows; i++)
		{
			if (Collision::AABB(A_marquee->dRect, A_KEY[i]->dRect) == true)
			{
				A_KEY[i]->activate = false;
				A_KEY[i]->resetpos(100, 0);
			}
		}
	}
	if (S_pressed == true)
	{
		S_marquee->uniquepos(150, 400);
		for (int i = 0; i < max_arrows; i++)
		{
			if (Collision::AABB(S_marquee->dRect, S_KEY[i]->dRect) == true)
			{
				S_KEY[i]->activate = false;
				S_KEY[i]->resetpos(150, 0);
			}
		}
	}

};
void Game::render() {
	SDL_RenderClear(renderer);
	for (int i = 0; i < max_arrows; i++)
	{
		if (A_KEY[i]->activate == true) A_KEY[i]->Render();
		if (S_KEY[i]->activate == true) S_KEY[i]->Render();
	}
	if (A_pressed == true) A_marquee->Render();
	if (S_pressed == true) S_marquee->Render();
	
	SDL_RenderPresent(renderer);
	A_pressed = false;
	S_pressed = false;

	
};
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
};

void Game::spawnobjectA() {

	for (int i = 0; i < max_arrows; i++)
	{
		if (A_KEY[i]->activate == false) {
			A_KEY[i]->activate = true;
			break;
		}
		
	}
	
}
void Game::spawnobjectS() {

	for (int i = 0; i < max_arrows; i++)
	{
		
		if (S_KEY[i]->activate == false)
		{
			S_KEY[i]->activate = true;
			break;
		}
	}

}

bool Game::randombool() {
	int x = rand() % 2;
	if (x == 0) return false;
	else return true;
}

