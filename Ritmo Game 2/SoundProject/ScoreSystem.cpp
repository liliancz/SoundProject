#include "ScoreSystem.h"
#include <stdio.h>


ScoreSystem::ScoreSystem() {};
ScoreSystem::~ScoreSystem() {};

void ScoreSystem::init() {
	multiplier = 1;
	hitscounter = 0;
	missedcounter = 0;
	score = 0;

};


void ScoreSystem::hittednotes() {
	hitscounter++;
	missedcounter = 0;
	if (hitscounter > multiplier)
	{
		multiplier++;
		int tmpscore = multiplier * hitscounter;
		score = score + tmpscore;
		hitscounter = 0;
	}
	

};

void ScoreSystem::missednotes() {
	missedcounter++;
	hitscounter = 0;
};

