//	Francois Charles Hebert
//	30 novembre 2020
//	Objet représentant le state du jeu principale du jeu Flappy birds.

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"
#include "state.hpp"
#include "pipe.h"
#include "land.h"
#include "bird.h"
#include "collision.h"
#include "flash.h"
#include "hud.h"
#include "gameOverState.h"
#include <sstream>
#include <iostream>
using namespace std;
using namespace sf;

class gameState : public state
{
private:
	gameDataRef _data;			// donne acces au statemachine, renderwindow, assertmanager, inputmanager
	Sprite  _background, _title, _playButton;	// l'ensemble des sprites du main menu.

	pipe* _pipe;
	land* _land;
	bird* _bird;

	collision _collision;
	flash* _flash;
	int _gameState;

	hud* _hud;
	int _score;

	SoundBuffer _hitSoundBuffer;
	SoundBuffer _pointSoundBuffer;
	SoundBuffer _wingSoundBuffer;
	Sound _hitSound;
	Sound _pointSound;
	Sound _wingSound;


	Clock _clock;

public:
	gameState(gameDataRef data);
	~gameState();
	const int getScore()const;

	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt)const;

};

