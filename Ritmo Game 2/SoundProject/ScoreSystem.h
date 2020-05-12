#pragma once
#ifndef _SCORESYSTEM_H
#define _SCORESYSTEM_H
#include "DrawText.h"

class ScoreSystem
{
	ScoreSystem();
	~ScoreSystem();



	int multiplier=1;
	int hitscounter;
	int missedcounter;

public:
	void init();
	void missednotes();
	void hittednotes();
	int score;
};



#endif // !_SCORESYSTEM_H


