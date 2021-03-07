#include "collision.h"

// Fonction qui verifie si une collision a lieu entre deux sprites.
// param: sprite sprite1     correspond au premier sprite
// param: sprite sprite2     correspond au deuxieme sprite
//return    true si une collision, false si aucune collision.
bool collision::checkSpriteCollision(Sprite sprite1, Sprite sprite2) const
{
	// Creation des rectangles de meme dimensions que les sprites recues en parametre.
	Rect<float> rect1 = sprite1.getGlobalBounds();
	Rect<float> rect2 = sprite2.getGlobalBounds();

	return rect1.intersects(rect2); //true s'ils entrent en contact.
}

// Fonction qui verifie si une collision a lieu entre deux sprites.
// param: sprite sprite1     correspond au premier sprite
// param: sprite sprite2     correspond au deuxieme sprite
//return    true si une collision, false si aucune collision.
bool collision::checkSpriteCollision(Sprite sprite1, float scale1, Sprite sprite2, float scale2) const
{
	// On ajuste la taille des sprites afin d'enlever le gap entre le bird et les objets lors des collisions.
	sprite1.setScale(scale1, scale1);
	sprite2.setScale(scale2, scale2);

	// Creation des rectangles de meme dimensions que les sprites recues en parametre.
	Rect<float> rect1 = sprite1.getGlobalBounds();
	Rect<float> rect2 = sprite2.getGlobalBounds();

	return rect1.intersects(rect2); //true s'ils entrent en contact.
}
