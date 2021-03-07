// Francois Charles Hebert
// 30 novembre 2020
// Objet pipe qui gere l'ensemble du head up display du jeu
#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include <list>
#include "game.h"
using namespace sf;

class hud
{
private:
	gameDataRef _data;
	Text _scoreText;
public:
	hud(gameDataRef data);
	void updateScore(int score);
	void draw()const;
};

