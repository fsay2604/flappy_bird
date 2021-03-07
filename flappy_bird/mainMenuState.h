//	Francois Charles Hebert
//	30 novembre 2020
//	Objet représentant le state du menu principale du jeu Flappy birds.

#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include <sstream>
#include <iostream>
using namespace std;
using namespace sf;

class mainMenuState : public state
{
private:
	gameDataRef _data;			// donne acces au statemachine, renderwindow, assertmanager, inputmanager
	Sprite  _background, _title, _playButton;	// contient l'ensemble des sprites du main menu. (title, sky, playButton)


public:
	mainMenuState(gameDataRef data);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt)const;

};
