///	Francois Charles Hebert
/// 25 novembre 2020
/// inputManager: Objet permettant de gerer input fait par un joueur pour faire reagir le jeu.

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class inputManager
{
public:
	bool isSpriteClicked(const Sprite& obj, Mouse::Button btn, RenderWindow& window);
	Vector2i getMousePosition(RenderWindow& window)const;
};

