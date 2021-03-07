// Francois Charles Hebert
// 02 decembre 2020
// Objet land qui gere le land du jeu flappy bird

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <vector>
#include "game.h"
using namespace sf;

class land
{
private:
	gameDataRef _data;
	vector<Sprite> _landSprites;
public:
	land(gameDataRef data);

	const vector<Sprite>& getSprites()const;

	void moveLand(float dt);
	void drawLand()const;
};

