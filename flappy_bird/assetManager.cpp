///	Francois Charles Hebert
/// 25 novembre 2020
/// assetManager: Objet permettant de gerer les elements dans les differentes states (aka fenetre);

#include "assetManager.h"

/// Fonction qui load une texture.
/// param string name		Contient le nom de la texture
/// param string fileName	Contient le nom de fichier de la texture a load.
void assetManager::loadTexture(string name, string fileName)
{
	Texture texture;

	if (texture.loadFromFile(fileName))
		_textures[name] = texture;
}

/// Fonction qui renvoit la texture correspondant au parametre.
/// return	Texture&	Correspond a la texture demander en parametre.
Texture& assetManager::getTexture(string name)
{
	return _textures.at(name);
}

/// Fonction qui load une font.
/// param string name		Contient le nom de la font
/// param string fileName	Contient le nom de fichier de la font a load.
void assetManager::loadFont(string name, string fileName)
{
	Font font;

	if (font.loadFromFile(fileName))
		_fonts[name] = font;
}

/// Fonction qui renvoit la texture correspondant au parametre.
/// return	Texture&	Correspond a la texture demander en parametre.
Font& assetManager::getFont(string name)
{
	return _fonts.at(name);
}
