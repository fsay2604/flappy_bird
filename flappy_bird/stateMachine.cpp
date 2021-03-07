///	Francois Charles Hebert
/// 25 novembre 2020
/// State de la machine.

#include "stateMachine.h"

/// Fonction qui permet d'ajouter une fenetre (aka un state).
/// param stateRef newstate		L'espace memoire ou l'on veut faire pointer le smartPointer _newState.
/// param bool isReplacing	Flags sp/cifiant si on remplace la fenetre
void stateMachine::addState(stateRef newstate, bool isReplacing)
{
	_isAdding = true;
	_isReplacing = isReplacing;

	_newState = move(newstate);
}


/// Fonction qui modifie le flag qui indique que l'on enleve un state. (le traitement se fait dans processStateChanges)
void stateMachine::removeState()
{
	_isRemoving = true;
}

/// Fonction qui gere si on ajoute, modifie ou enleve un state.
void stateMachine::processStateChanges()
{
	//	Si on retire et que la pile de state n'est pas vide.
	if (_isRemoving && !_states.empty())
	{
		_states.pop();
		if (!_states.empty())
			_states.top()->resume();
	}
	_isRemoving = false;					//	Reset le flag.

	//	Si on ajoute une fenetre (state) ou on la modifie. (dans les deux cas on push une nouvelle state).
	if (_isAdding)
	{
		if (!_states.empty())				//	Si la pile de state n'est pas vide
		{
			if (_isReplacing)
				_states.pop();				//	Si on modifie, on pop le state pour ajouter le state modifier.
			else
				_states.top()->pause();		//	Sinon on fait un pause du top.
		}

		_states.push(move(_newState));		//	On ajoute le nouveau state ou le state modifiee.
		_states.top()->init();				//	On init le top qui est maintenant le new state.
		_isAdding = false;					//	Reset le flag.
	}
}

/// Getter du top de la pile. (aka La fenetre active.)
/// return stateRef&	un smartPointer representant la fenetre active.
stateRef& stateMachine::getActiveState()
{
	return _states.top();
}
