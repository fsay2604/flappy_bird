///	Francois Charles Hebert
/// 25 novembre 2020
/// inputManager: Objet permettant de gerer input fait par un joueur pour faire reagir le jeu.

#include "inputManager.h"


/// Fonction qui verifie si on a cliquer sur le sprite d ela fenetre recu en parametre.
bool inputManager::isSpriteClicked(const Sprite& obj, Mouse::Button btn, RenderWindow& window)
{
	if (Mouse::isButtonPressed(btn))
	{
		IntRect tempRect(obj.getPosition().x, obj.getPosition().y,
			obj.getGlobalBounds().width, obj.getGlobalBounds().height);

		if (tempRect.contains(Mouse::getPosition(window)))
			return true;
	}
	return false;
}


/// Fonction qui retourne la position de la souris de la fenetre recu en parametre.
Vector2i inputManager::getMousePosition(RenderWindow& window) const
{
	return Mouse::getPosition(window);
}
