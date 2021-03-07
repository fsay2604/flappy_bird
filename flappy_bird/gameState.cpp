#include "gameState.h"
#include "gameOverState.h"

gameState::gameState(gameDataRef data) : _data(data)
{
	_pipe = nullptr;
	_land = nullptr;
	_bird = nullptr;
	_flash = nullptr;
	_hud = nullptr;
	_score = 0;
	_gameState = gameStates::ready;
}

gameState::~gameState()
{
	delete _pipe;
	delete _land;
	delete _bird;
	delete _flash;
	delete _hud;
}

const int gameState::getScore() const
{
	return _score;
}

void gameState::init()
{
	_gameState = gameStates::ready;

	// Background
	_data->assets.loadTexture("main menu background", MAIN_MENU_STATE_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("main menu background"));

	// Pipes
	_data->assets.loadTexture("pipe up", PIPE_UP_FILEPATH);
	_data->assets.loadTexture("pipe down", PIPE_DOWN_FILEPATH);
	_pipe = new pipe(_data);	// Creation d'une pipe

	// Land
	_data->assets.loadTexture("land", LAND_FILEPATH);
	_land = new land(_data);	// Creation du land

	// Bird
	_data->assets.loadTexture("bird frame 1", BIRD_FRAME_1_FILEPATH);
	_data->assets.loadTexture("bird frame 2", BIRD_FRAME_2_FILEPATH);
	_data->assets.loadTexture("bird frame 3", BIRD_FRAME_3_FILEPATH);
	_data->assets.loadTexture("bird frame 4", BIRD_FRAME_4_FILEPATH);
	_bird = new bird(_data);

	// Flash screen upon death
	_flash = new flash(_data);

	// Scoring system
	_data->assets.loadTexture("scoring pipe", PIPE_SCORING_FILEPATH);
	_data->assets.loadFont("flappy font", FLAPPY_FONT_FILEPATH);
	_hud = new hud(_data);

	// Sons
	if (!_hitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	if (!_wingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	if (!_pointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH)) {
		cout << "erreur loading sound effect" << endl;
	}
	_hitSound.setBuffer(_hitSoundBuffer);
	_pointSound.setBuffer(_pointSoundBuffer);
	_wingSound.setBuffer(_wingSoundBuffer);

}

void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_background, Mouse::Left, _data->window))
		{
			if (_gameState != gameStates::gameOver)
			{
				_gameState = gameStates::playing;
				_bird->tap();
				_wingSound.play();
			}
		}
	}
}

void gameState::update(float dt)
{
	if (_gameState != gameStates::gameOver)
	{
		_bird->animate(dt);
		_land->moveLand(dt);
	}

	if (_gameState == gameStates::playing)
	{
		_pipe->movePipes(dt);
		if (_clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
		{
			_pipe->spawnScoringPipes();
			_pipe->randomisePipeOffset();
			_pipe->spawnBottomPipe();
			_pipe->spawnTopPipe();

			_clock.restart();
		}

		_bird->update(dt);

		// Verification des collisions avec le land.
		vector<Sprite> landSprites = _land->getSprites();
		for (int i = 0; i < landSprites.size(); i++)
			if (_collision.checkSpriteCollision(_bird->getSprite(), 0.7f, landSprites.at(i), 1.0f))
			{
				_gameState = gameStates::gameOver;
				_hitSound.play();
				_clock.restart();
			}

		// Verification des collisions avec les pipes
		list<Sprite> pipes = _pipe->getSprites();
		list<Sprite>::iterator it = pipes.begin();
		for (it; it != pipes.end(); it++)
			if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, *it, 1.0f))
			{
				_gameState = gameStates::gameOver;
				_hitSound.play();
				_clock.restart();
			}


		// Verification avec les scoring pipes
		it = _pipe->getScoringSprites().begin();
		while (it != _pipe->getScoringSprites().end())
		{
			if (_gameState == gameStates::gameOver)
				break;

			if (_collision.checkSpriteCollision(_bird->getSprite(), 0.625f, *it, 1.0f))
			{
				_score++;
				_pointSound.play();
				_hud->updateScore(_score);
				it = _pipe->getScoringSprites().erase(it);
			}
			else
				it++;
		}

	}

	if (_gameState == gameStates::gameOver)
	{
		_flash->show(dt);
		if (_clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
		{
			_data->machine.addState(stateRef(new gameOverState(_data, _score)), true);
		}

	}

}

void gameState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_pipe->drawPipes();
	_land->drawLand();
	_hud->draw();
	_bird->draw();
	_flash->draw();
	_data->window.display();
}
