#include "MusicManager.h"
#include "SDL2-2.0.12/include/SDL.h"
#include <stdio.h>

MusicManager::MusicManager(const char* filename){
    music = Mix_LoadMUS(filename);
    if (music == NULL)
    {
        printf(Mix_GetError());

    }

};
MusicManager::~MusicManager() {};

void MusicManager::load_chunk(const char* filename) {
    chunk = Mix_LoadWAV(filename);
    if (chunk == NULL)
    {
        printf(Mix_GetError());
    
    }
};

void MusicManager::load_music(const char* filename) {
    music = Mix_LoadMUS(filename);
    if (music == NULL)
    {
        printf(Mix_GetError());

    }

};

void MusicManager::clean() {
    Mix_FreeChunk(chunk);
    Mix_FreeMusic(music);
    Mix_CloseAudio();
};

void MusicManager::play_chunk() {
    if (Mix_PlayChannel(-1, chunk, 0) == -1)
    {
        printf(Mix_GetError());
    }
};

void MusicManager::pause_music() {

    //If there is no music playing
    if (Mix_PlayingMusic() == 0)
    {
        //Play the music
        Mix_PlayMusic(music, -1);

    }
    else
    {
        //If the music is paused
        if (Mix_PausedMusic() == 1)
        {
            //Resume the music
            Mix_ResumeMusic();
        }
        //If the music is playing
        else
        {
            //Pause the music
            Mix_PauseMusic();
        }
    }

};

void MusicManager::stop_music() {
    //Stop the music
    Mix_HaltMusic();

};
