#include "bird.h"

bird::bird(gameDataRef data) : _data(data)
{
	_animationIterator = _rotation = 0;

	_animationFrames.push_back(_data->assets.getTexture("bird frame 1"));
	_animationFrames.push_back(_data->assets.getTexture("bird frame 2"));
	_animationFrames.push_back(_data->assets.getTexture("bird frame 3"));
	_animationFrames.push_back(_data->assets.getTexture("bird frame 4"));

	_birdSprite.setTexture(_animationFrames.at(_animationIterator));

	_birdSprite.setPosition((_data->window.getSize().x / 4) - _birdSprite.getGlobalBounds().width / 2,
		(_data->window.getSize().y / 2) - _birdSprite.getGlobalBounds().height / 2);
	_birdSprite.setOrigin(_birdSprite.getGlobalBounds().width / 2, _birdSprite.getGlobalBounds().height / 2);	// On met l'origine au centre du sprite pour la rotation

	_birdState = BIRD_STATE_STILL;
}

const Sprite& bird::getSprite() const
{
	return _birdSprite;
}

// Fonction qui gere l'animation du bird.
void bird::animate(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > (BIRD_ANIMATION_DURATION / _animationFrames.size()))
	{
		_animationIterator++;
		if (_animationIterator >= _animationFrames.size())
			_animationIterator = 0;

		_birdSprite.setTexture(_animationFrames.at(_animationIterator));

		_clock.restart();
	}
}

// Fonction qui update le state du bird en fonction de si il vole ou tombe.
void bird::update(float dt)
{
	if (_birdState == BIRD_STATE_FALLING)	// si le bird tombe
	{
		_birdSprite.move(0, GRAVITY * dt);

		_rotation += ROTATION_SPEED * dt;
		if (_rotation > 25.0f)
			_rotation = 25.0f;
		_birdSprite.setRotation(_rotation);
	}
	else if (_birdState == BIRD_STATE_FLYING)	// si le bird vole
	{
		_birdSprite.move(0, -FLYING_SPEED * dt);
		_rotation -= ROTATION_SPEED * dt;
		if (_rotation < -25.0f)
			_rotation = -25.0f;
		_birdSprite.setRotation(_rotation);
	}

	if (_mouvementClock.getElapsedTime().asSeconds() > FLYING_DURATION)	// gere le temps de vole avant de changer de state pour tomber
	{
		_birdState = BIRD_STATE_FALLING;
		_mouvementClock.restart();
	}
}
// Fonction qui gere l'input du click
void bird::tap()
{
	_mouvementClock.restart();
	_birdState = BIRD_STATE_FLYING;
}

void bird::draw() const
{
	_data->window.draw(_birdSprite);
}
