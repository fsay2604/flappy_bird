//	Francois Charles Hebert
//	02 decembre 2020
//	Objet flash screen upon death.

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
using namespace sf;

class flash
{
private:
	gameDataRef _data;
	RectangleShape _shape;
	bool _flashOn;
public:
	flash(gameDataRef data);
	void show(float dt);
	void draw();
};

