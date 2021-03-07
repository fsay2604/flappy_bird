#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include <sstream>
#include <iostream>
using namespace std;
using namespace sf;

class splashState : public state
{
private:
	gameDataRef _data;	// donne acces au statemachine, renderwindow, assertmanager, inputmanager
	Clock _clock;
	Sprite _background;

public:
	splashState(gameDataRef data);

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt)const;

};

