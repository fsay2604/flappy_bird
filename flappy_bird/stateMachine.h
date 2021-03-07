///	Francois Charles Hebert
/// 25 novembre 2020
/// State de la machine.

#pragma once
#include <memory>
#include <stack>
#include "state.hpp"	//	Heritage
using namespace std;

typedef unique_ptr<state> stateRef;		//	smartpointer de state.

class stateMachine
{
private:
	stack<stateRef> _states;	// Stack de ptr pour empiler les fenetres du jeu.
	stateRef _newState;			// La fenetre active

	//	Flags pour savoir ce qui se passe dans la fenetre.
	bool _isRemoving;
	bool _isAdding;
	bool _isReplacing;

public:
	void addState(stateRef newstate, bool isReplacing = true);
	void removeState();

	void processStateChanges();
	stateRef& getActiveState();
};

