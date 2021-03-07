//	Francois Charles Hebert
//	02 novembre 2020
//	Objet qui verifie les collisions dans le jeu flappy bird

#pragma once
#include "game.h"
using namespace sf;

class collision
{
private:
public:
	bool checkSpriteCollision(Sprite sprite1, Sprite sprite2) const;
	bool checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const;
};

