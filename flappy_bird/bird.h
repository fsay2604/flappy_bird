//	Francois Charles Hebert
//	02 decembre 2020
//	Objet représentant le bird du du jeu Flappy birds.

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
using namespace sf;

class bird
{
private:
	gameDataRef _data;
	Sprite _birdSprite;	// a modifier selon l'animation

	vector<Texture> _animationFrames;
	int _animationIterator;
	Clock _clock;

	Clock _mouvementClock;
	int _birdState;

	float _rotation;
public:
	bird(gameDataRef data);

	const Sprite& getSprite()const;

	void animate(float dt);
	void update(float dt);
	void tap();
	void draw()const;
};

