#include "mainMenuState.h"
#include "gameState.h"

mainMenuState::mainMenuState(gameDataRef data) : _data(data)
{
}

void mainMenuState::init()
{
	float XaxisCenter = SCREEN_WIDTH / 2;
	float YaxisCenter = SCREEN_HEIGHT / 2;

	_data->assets.loadTexture("main menu background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("main menu background"));

	_data->assets.loadTexture("main menu title", GAME_TITLE_FILEPATH);
	_title.setTexture(_data->assets.getTexture("main menu title"));
	_title.setPosition(XaxisCenter - (_title.getGlobalBounds().width / 2), (_title.getGlobalBounds().height / 2));

	_data->assets.loadTexture("main menu play button", PLAY_BUTTON_FILEPATH);
	_playButton.setTexture(_data->assets.getTexture("main menu play button"));
	_playButton.setPosition(XaxisCenter - (_playButton.getGlobalBounds().width / 2), YaxisCenter - (_title.getGlobalBounds().height / 2));
}

// Fonction qui gere les inputs de l'utilisateur sur cette state.
void mainMenuState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_playButton, Mouse::Left, _data->window))
		{
			// todo: ajouter le state du jeu principal.
			_data->machine.addState(stateRef(new gameState(_data)), true);
		}
	}
}

void mainMenuState::update(float dt)
{
}

void mainMenuState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_title);
	_data->window.draw(_playButton);
	_data->window.display();
}
