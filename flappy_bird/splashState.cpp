#include "splashState.h"
#include "mainMenuState.h"

splashState::splashState(gameDataRef data) : _data(data)
{
}

void splashState::init()
{
	_data->assets.loadTexture("Logo state background", SPLASH_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("Logo state background"));
}

void splashState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
	}
}

void splashState::update(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > LOGO_STATE_SHOW_TIME)
	{
		//todo call menustate
		_data->machine.addState(stateRef(new mainMenuState(_data)), true);
	}

}

void splashState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}
