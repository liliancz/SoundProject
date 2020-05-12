#pragma once
#ifndef _MUSICMANAGER_H
#define _MUSICMANAGER_H

#include "SDL2_mixer-2.0.4/include/SDL_mixer.h"

class MusicManager
{

public:
	MusicManager(const char* filename);
	~MusicManager();
	void load_chunk(const char* filename);
	void load_music(const char* filename);
	void clean();
	void play_chunk();
	void pause_music();
	void stop_music();
	Mix_Music* music;
	Mix_Chunk* chunk;

};
#endif

