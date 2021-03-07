#include "gameOverState.h"
#include "gameState.h"

gameOverState::gameOverState(gameDataRef data, int score) :_data(data), _score(score)
{
}

void gameOverState::init()
{
	float centerWindowX = _data->window.getSize().x / 2;
	float centerWindowY = _data->window.getSize().y / 2;


	// Background
	_data->assets.loadTexture("game over background", GAME_OVER_BACKGROUND_FILEPATH);
	_background.setTexture(_data->assets.getTexture("game over background"));

	// Container	
	_data->assets.loadTexture("game over container", GAME_OVER_BODY_FILEPATH);
	_gameOverContainer.setTexture(_data->assets.getTexture("game over container"));
	_gameOverContainer.setPosition(centerWindowX - _gameOverContainer.getGlobalBounds().width / 2, centerWindowY - _gameOverContainer.getGlobalBounds().height / 2);

	// Title
	_data->assets.loadTexture("game over title", GAME_OVER_TITLE_FILEPATH);
	_gameOverTitle.setTexture(_data->assets.getTexture("game over title"));
	_gameOverTitle.setPosition(centerWindowX - _gameOverTitle.getGlobalBounds().width / 2, centerWindowY - _gameOverContainer.getGlobalBounds().height * 1.2);

	// RetryButton
	_data->assets.loadTexture("retry button", PLAY_BUTTON_FILEPATH);
	_retryButton.setTexture(_data->assets.getTexture("retry button"));
	_retryButton.setPosition(centerWindowX - _retryButton.getGlobalBounds().width / 2, _gameOverContainer.getPosition().y + _gameOverContainer.getGlobalBounds().height + _retryButton.getGlobalBounds().height * 0.2);

	// HighScore
	string scoreLu;
	std::ifstream myFile;
	myFile.open("./resources/res/highScore.txt");
	if (myFile.is_open())
	{
		myFile >> scoreLu;
		_highScore = stoi(scoreLu);
		myFile.close();
	}
	else
		std::cout << "Erreur d<ouverture de fichier." << endl;

	if (_score > _highScore)
	{
		std::ofstream myFile;
		myFile.open("./resources/res/highScore.txt");
		myFile << _score;
		_highScore = _score;
		myFile.close();
	}

	// Text
	_scoreText.setFont(_data->assets.getFont("flappy font"));
	_highScoreText.setFont(_data->assets.getFont("flappy font"));

	_scoreText.setString(to_string(_score));
	_highScoreText.setString(to_string(_highScore));

	_scoreText.setCharacterSize(56);
	_highScoreText.setCharacterSize(56);

	_scoreText.setFillColor(Color::White);
	_highScoreText.setFillColor(Color::White);

	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2,
		_scoreText.getGlobalBounds().height / 2);
	_highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2,
		_highScoreText.getGlobalBounds().height / 2);

	_scoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 2.15);
	_highScoreText.setPosition(_data->window.getSize().x / 10 * 7.25, _data->window.getSize().y / 1.78);

	// medal
	_data->assets.loadTexture("bronze", BRONZE_MEDAL_FILEPATH);
	_data->assets.loadTexture("silver", SILVER_MEDAL_FILEPATH);
	_data->assets.loadTexture("gold", GOLD_MEDAL_FILEPATH);
	_data->assets.loadTexture("platinum", PLATINUM_MEDAL_FILEPATH);

	if (_score >= BRONZE_MEDAL_SCORE && _score < SILVER_MEDAL_SCORE)
		_medal.setTexture(_data->assets.getTexture("bronze"));
	else if (_score >= SILVER_MEDAL_SCORE && _score < GOLD_MEDAL_SCORE)
		_medal.setTexture(_data->assets.getTexture("silver"));
	else if (_score >= GOLD_MEDAL_SCORE && _score < PLATINUM_MEDAL_SCORE)
		_medal.setTexture(_data->assets.getTexture("gold"));
	else
		_medal.setTexture(_data->assets.getTexture("platinum"));
	_medal.setPosition(175, 465);
}

void gameOverState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
		else if (_data->input.isSpriteClicked(_retryButton, Mouse::Left, _data->window))
		{
			_data->machine.addState(stateRef(new gameState(_data)), true);
		}
	}
}

void gameOverState::update(float dt)
{
}

void gameOverState::draw(float dt) const
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_gameOverTitle);
	_data->window.draw(_gameOverContainer);
	_data->window.draw(_retryButton);
	_data->window.draw(_scoreText);
	_data->window.draw(_highScoreText);
	_data->window.draw(_medal);
	_data->window.display();
}
