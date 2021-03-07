#include "land.h"

land::land(gameDataRef data) : _data(data)
{
	Sprite sprite1(_data->assets.getTexture("land"));
	Sprite sprite2(_data->assets.getTexture("land"));

	// En bas de l'ecran en y, 0 en x
	sprite1.setPosition(0, _data->window.getSize().y - sprite1.getGlobalBounds().height);
	// A la fin du premier land
	sprite2.setPosition(sprite1.getGlobalBounds().width, _data->window.getSize().y - sprite1.getGlobalBounds().height);

	_landSprites.push_back(sprite1);
	_landSprites.push_back(sprite2);
}

const vector<Sprite>& land::getSprites() const
{
	return _landSprites;
}

void land::moveLand(float dt)
{
	for (int i = 0; i < _landSprites.size(); i++)
	{
		float movement = PIPE_MOVEMENT_SPEED * dt;
		_landSprites.at(i).move(-movement, 0);

		if (_landSprites.at(i).getPosition().x < (0 - _landSprites.at(i).getGlobalBounds().width))
		{
			//repositionne a droite de l'ecran
			Vector2f position(_data->window.getSize().x, _landSprites.at(i).getPosition().y);
			_landSprites.at(i).setPosition(position);
		}
	}
}

void land::drawLand()const
{
	for (int i = 0; i < _landSprites.size(); i++)
		_data->window.draw(_landSprites.at(i));
}
