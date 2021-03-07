#include "pipe.h"

pipe::pipe(gameDataRef data) : _data(data)
{
	_pipeSpawnYoffset = 0;
}

const list<Sprite>& pipe::getSprites() const
{
	return _pipeSprites;
}

list<Sprite>& pipe::getScoringSprites()
{
	return _scoringPipes;
}

void pipe::randomisePipeOffset()
{
	_pipeSpawnYoffset = rand() % (MAX_PIPE_HEIGHT + 1);
}
// Spawn une pipe dans le bas de l'ecran (ouverture vers le haut ).
void pipe::spawnTopPipe()
{
	Sprite sprite(_data->assets.getTexture("pipe up"));
	sprite.setPosition(_data->window.getSize().x, _data->window.getSize().y - sprite.getGlobalBounds().height - _pipeSpawnYoffset);
	_pipeSprites.push_back(sprite);
}

void pipe::spawnBottomPipe()
{
	Sprite sprite(_data->assets.getTexture("pipe down"));
	sprite.setPosition(_data->window.getSize().x, 0 - _pipeSpawnYoffset);
	_pipeSprites.push_back(sprite);
}

void pipe::spawnScoringPipes()
{
	Sprite sprite(_data->assets.getTexture("scoring pipe"));
	sprite.setPosition(_data->window.getSize().x, 0);
	_scoringPipes.push_back(sprite);
}

void pipe::movePipes(float dt)
{
	list<Sprite>::iterator it = _pipeSprites.begin();
	while (it != _pipeSprites.end())
	{
		// Si une pipe depasse l'ecran, on l'efface de la liste.
		if (it->getPosition().x < (0 - it->getGlobalBounds().width))
			it = _pipeSprites.erase(it);
		else
		{
			float movement = PIPE_MOVEMENT_SPEED * dt;
			it->move(-movement, 0);	// deplacement vers la gauche, -x
			it++;
		}
	}

	it = _scoringPipes.begin();
	while (it != _scoringPipes.end())
	{
		float movement = PIPE_MOVEMENT_SPEED * dt;
		it->move(-movement, 0);	// deplacement vers la gauche, -x
		it++;

	}
}

// Imprime a l'ecran l'ensemble des pipes dans la liste.
void pipe::drawPipes()
{
	for (list<Sprite>::iterator it = _scoringPipes.begin(); it != _scoringPipes.end(); it++)
		_data->window.draw(*it);
	for (list<Sprite>::iterator it = _pipeSprites.begin(); it != _pipeSprites.end(); it++)
		_data->window.draw(*it);
}
