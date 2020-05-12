#pragma once
#ifndef _MUSICMANAGER_H
#define _MUSICMANAGER_H

#include "SDL2_mixer-2.0.4/include/SDL_mixer.h"

class MusicManager
{

public:
	MusicManager(const char* filename);
	~MusicManager();

	void clean();
	void pause_music();
	void stop_music();
	Mix_Music* music = NULL;


};


class MusicManagerChunk
{

public:
	MusicManagerChunk(const char* filename);
	~MusicManagerChunk();

	
	void clean();
	void play_chunk();


	Mix_Chunk* chunk = NULL;

};
#endif

