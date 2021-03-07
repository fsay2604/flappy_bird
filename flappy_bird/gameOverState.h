//	Francois Charles Hebert
//	30 novembre 2020
//	Objet représentant le state du jeu lorsque l'on perd, du jeu Flappy birds.

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include <sstream>
#include <fStream>
#include <iostream>
using namespace std;
using namespace sf;

class gameOverState : public state
{
private:
	gameDataRef _data;			// donne acces au statemachine, renderwindow, assetmanager, inputmanager
	Sprite  _background, _gameOverTitle, _gameOverContainer, _retryButton, _medal;
	Text _scoreText, _highScoreText;
	int _score, _highScore;

public:
	gameOverState(gameDataRef data, int score);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt)const;

};


