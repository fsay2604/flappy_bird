///	Francois Charles Hebert
/// 27 novembre 2020
/// inputManager: Objet game d'un flappy bird.
#include "game.h"
#include "splashState.h"
#include "gameOverState.h"

// Constructeur de la game
game::game(int width, int height, string title)
{
	srand(time(0));

	_data = make_shared<gameData>();	// creation de la game en memoire dynamique.
	_data->window.create(VideoMode(width, height), title, Style::Close | Style::Titlebar);	// Creation de la fenetre qui changera de contenu selon la state cree ensuite.

	//to do : creation d<un 1er etat de jeu. (aka premiere fenetre.)
	_data->machine.addState(stateRef(new splashState(_data)));
	run();
}

// Fonction qui fait la game loop
void game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = _clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;


	while (_data->window.isOpen())
	{

		_data->machine.processStateChanges();	// Verifie si il y a des changements.

		newTime = _clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;					// si on depasse .25 sec, on ajuste a .25sec pour le calcul de l'accumulator.

		currentTime = newTime;
		accumulator += frameTime;				// accumulator accumule tout les frameTIme.

		while (accumulator >= dt)				// si on depasse le temps du frame, on verifie les evennements et on update la fenetre.
		{
			_data->machine.getActiveState()->handleInput();
			_data->machine.getActiveState()->update(dt);
			accumulator -= dt;					//	On retire dt de accumulator pour l'interpolation
		}

		interpolation = accumulator / dt;		//	Temps d'exection de la loop pour le draw.
		_data->machine.getActiveState()->draw(interpolation);
	}
}
