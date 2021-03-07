// Francois Charles Hebert
// 30 novembre 2020
// Objet pipe qui gere les pipes du jeu flappy bird

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <list>
#include "game.h"
using namespace sf;

class pipe
{
private:
	gameDataRef _data;
	list<Sprite> _pipeSprites, _scoringPipes;
	int _pipeSpawnYoffset;

public:
	pipe(gameDataRef data);
	const list<Sprite>& getSprites()const;
	list<Sprite>& getScoringSprites();

	void randomisePipeOffset();

	void spawnTopPipe();
	void spawnBottomPipe();
	void spawnScoringPipes();

	void movePipes(float dt);

	void drawPipes();
};

