#pragma warning(disable : 4996).
#include "Game.h"
#include "Object.h"
#include "TextureM.h"
#include "Collision.h"
#include "DrawText.h"
#include "MusicManager.h"
#include "ScoreSystem.h"
#include <stdlib.h>     /* srand, rand */
#include <stdio.h>
#include "SDL2-2.0.12/include/SDL.h"
#include "Constants.h"
#pragma warning(disable : 4995)

Game::Game(){};
Game::~Game(){};

const int max_arrows = 100;
Object* A_KEY[max_arrows];
Object* S_KEY[max_arrows];

Object* K_KEY[max_arrows];
Object* L_KEY[max_arrows];

Object* A_marquee;
Object* S_marquee;
Object* K_marquee;
Object* L_marquee;

Object* arrow;

Object* Red_square;
Object* Blue_square;
Object* Purple_square;
Object* Green_square;

const int max_text = 5;
DrawText* text[max_text];

bool A_pressed = false;
bool S_pressed = false;
bool L_pressed = false;
bool K_pressed = false;

MusicManager* song;
MusicManager* wrongkey;

ScoreSystem* GameScore; // worst score system ever made by me



void Game::Init(const char* title, int xpos, int ypos, int width, int height) {

	if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_AUDIO) == 0)
	{	
		
		window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		//Initialize SDL_ttf
		if (TTF_Init() == -1)
		{
			isRunning = false;
		}
		if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		{
			printf(Mix_GetError());
			isRunning = false;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	for (int i = 0; i < max_arrows; i++)
	{
		A_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, C1, 0);
		S_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, C2, 0);
		K_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, C3, 0);
		L_KEY[i] = new Object("assets/Red_Music_Note.png", renderer, C4, 0);
		
	}

	Purple_square = new Object("assets/purple_square.png", renderer, C1, 400);
	Blue_square = new Object("assets/blue_square.png", renderer, C2, 400);
	Red_square = new Object("assets/red_square.png", renderer, C3, 400);
	Green_square = new Object("assets/green_square.png", renderer, C4, 400);


	A_marquee = new Object("assets/Marquee_Music_Note.png", renderer, C1, 400);
	S_marquee = new Object("assets/Marquee_Music_Note.png", renderer, C2, 400);
	K_marquee = new Object("assets/Marquee_Music_Note.png", renderer, C3, 400);
	L_marquee = new Object("assets/Marquee_Music_Note.png", renderer, C4, 400);

	arrow = new Object("assets/arrow_1.png", renderer, 36, 400);
	text[0] = new DrawText(renderer, "Good", SCREEN_WIDTH/2-50, SCREEN_WIDTH/2, 50);
	song = new MusicManager("assets/Borgore_Tetris.wav");
	song->pause_music();
	

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
			break;
		case SDLK_s:
			S_pressed = true;
			break;
		case SDLK_k:
			K_pressed = true;
			break;
		case SDLK_l:
			L_pressed = true;
			break;
		}
	default:
		break;
	}
};
void Game::update(float t) {
	
	Purple_square->uniquepos(C1, 400);
	Blue_square->uniquepos(C2, 400);
	Green_square->uniquepos(C3, 400);
	Red_square->uniquepos(C4, 400);

	for (int i = 0; i < max_arrows; i++)
	{
		if (A_KEY[i]->activate == true)
		{
			A_KEY[i]->Update(t);
		}
		if (S_KEY[i]->activate == true)
		{
			S_KEY[i]->Update(t);
		}
		if (K_KEY[i]->activate == true)
		{
			K_KEY[i]->Update(t);
		}
		if (L_KEY[i]->activate == true)
		{
			L_KEY[i]->Update(t);
		}
	}
	if (A_pressed == true)
	{
		A_marquee->uniquepos(C1, 400);
		for (int i = 0; i < max_arrows; i++)
		{
			if (Collision::AABB(A_marquee->dRect, A_KEY[i]->dRect) == true)
			{
				
				A_KEY[i]->activate = false;
				A_KEY[i]->resetpos(C1, 0);
			}
			else
			{
				
			}
		}
	}
	if (S_pressed == true)
	{
		S_marquee->uniquepos(C2, 400);
		for (int i = 0; i < max_arrows; i++)
		{
			if (Collision::AABB(S_marquee->dRect, S_KEY[i]->dRect) == true)
			{
				
				S_KEY[i]->activate = false;
				S_KEY[i]->resetpos(C2, 0);
			}
			else
			{
	
			}
		}
	}
	if (K_pressed == true)
	{
		K_marquee->uniquepos(C3, 400);
		for (int i = 0; i < max_arrows; i++)
		{
			if (Collision::AABB(K_marquee->dRect, K_KEY[i]->dRect) == true)
			{

				K_KEY[i]->activate = false;
				K_KEY[i]->resetpos(C3, 0);
			}
			else
			{

			}
		}
	}
	if (L_pressed == true)
	{
		L_marquee->uniquepos(C4, 400);
		for (int i = 0; i < max_arrows; i++)
		{
			if (Collision::AABB(L_marquee->dRect, L_KEY[i]->dRect) == true)
			{

				L_KEY[i]->activate = false;
				L_KEY[i]->resetpos(C4, 0);
			}
			else
			{

			}
		}
	}

	arrow->uniquepos(36, 400);
	text[0]->Update();


};
void Game::render() {

	SDL_RenderClear(renderer);

	Purple_square->Render();
	Red_square->Render();
	Blue_square->Render();
	Green_square->Render();
	// stuff to render
	
	

	for (int i = 0; i < max_arrows; i++)
	{
		if (A_KEY[i]->activate == true) A_KEY[i]->Render();
		if (S_KEY[i]->activate == true) S_KEY[i]->Render();
		if (K_KEY[i]->activate == true) K_KEY[i]->Render();
		if (L_KEY[i]->activate == true) L_KEY[i]->Render();
	}
	if (A_pressed == true) A_marquee->Render();
	if (S_pressed == true) S_marquee->Render();
	if (K_pressed == true) K_marquee->Render();
	if (L_pressed == true) L_marquee->Render();

	arrow->Render();
	text[0]->Render();
	
	
	
	SDL_RenderPresent(renderer);
	//reset pressed	
	A_pressed = false;
	S_pressed = false;
	K_pressed = false;
	L_pressed = false;
	
};
void Game::clean() {
	
	text[0]->Clean();
	song->clean();
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

};
void Game::spawnobjectS() {

	for (int i = 0; i < max_arrows; i++)
	{

		if (S_KEY[i]->activate == false)
		{
			S_KEY[i]->activate = true;
			break;
		}
	}

};
void Game::spawnobjectK() {

	for (int i = 0; i < max_arrows; i++)
	{
		if (K_KEY[i]->activate == false) {
			K_KEY[i]->activate = true;
			break;
		}

	}

};
void Game::spawnobjectL() {

	for (int i = 0; i < max_arrows; i++)
	{
		if (L_KEY[i]->activate == false) {
			L_KEY[i]->activate = true;
			break;
		}

	}

};

bool Game::randombool() {
	int x = rand() % 2;
	if (x == 0) return false;
	else return true;
};

