#include "flash.h"

flash::flash(gameDataRef data) : _data(data)
{
	_shape = RectangleShape(Vector2f(_data->window.getSize()));
	_shape.setFillColor(Color(255, 255, 255, 0));	// Blanc transparent.
	_flashOn = true;
}
// Montre a l'ecran un blanc opaque (le flash) en modifiant la transparence de la fenetre (0=transparent, 255=opaque)
void flash::show(float dt)
{
	int alpha;
	if (_flashOn)
	{
		alpha = (int)_shape.getFillColor().a + (FLASH_SPEED * dt);

		if (alpha >= 255.0f)
		{
			alpha = 255.0f;
			_flashOn = false;
		}
	}
	else
	{
		alpha = (int)_shape.getFillColor().a - (FLASH_SPEED * dt);
		if (alpha <= 0.0f)
			alpha = 0.0f;
	}
	_shape.setFillColor(Color(255, 255, 255, alpha));
}

void flash::draw()
{
	_data->window.draw(_shape);
}

