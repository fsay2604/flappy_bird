///	Francois Charles Hebert
/// 25 novembre 2020
/// Objet permettant de representer les differentes fenetres d'un jeu (state) contenant des assets. C'est le frame de toutes les states.

#pragma once

class state
{
public:
	virtual void init() = 0;					//	Initialise la state.
	virtual void handleInput() = 0;				//	Gere tout les inputs de la fenetre.
	virtual void update(float delta) = 0;		//	Update la fenetre apres l'input.
	virtual void draw(float delta)const = 0;	//	Draw la fenetre apres update, delta est la difference de temps avec le frame rate.

	virtual void pause() {};
	virtual void resume() {};
};