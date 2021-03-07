///	Francois Charles Hebert
/// 25 novembre 2020
/// assetManager: Objet permettant de gerer les elements dans les differentes states (aka fenetre);

#pragma once
#include <map>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class assetManager
{
private:
	map<string, Texture> _textures;		// Association du nom de la texture a la texture sfml.
	map<string, Font>	_fonts;			// Association du nom de la font a la font sfml.

public:
	void loadTexture(string name, string fileName);
	Texture& getTexture(string name);

	void loadFont(string name, string fileName);
	Font& getFont(string name);
};

