///	Francois Charles Hebert
/// 27 novembre 2020
/// inputManager: Objet game d'un flappy bird.

#pragma once
#include <string>
#include <memory>
#include "state.hpp"
#include "stateMachine.h"
#include "assetManager.h"
#include "inputManager.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace std;
using namespace sf;

struct gameData
{
	stateMachine machine;
	RenderWindow window;
	assetManager assets;
	inputManager input;
};

typedef shared_ptr<gameData> gameDataRef;

class game
{
private:
	const float dt = 1.0f / 60.0f;	// Temps pour chaque frame. (60fps)
	Clock _clock;
	gameDataRef _data;	// ptr sur la struct gameData.
public:
	game(int width, int height, string title);
	void run();
};

