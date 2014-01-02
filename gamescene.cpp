#include "gamescene.hpp"
#include <SDL/SDL.h>
#include "ship.hpp"
#include "asteroid.hpp"
#include "score.hpp"

GameScene::GameScene()
{
	Ship *ship = new Ship();
	Score *score = new Score();

	addEntity(ship);
	addRenderable(ship);

	addEntity(score);
	addRenderable(score);

	generateAsteroids();
}

GameScene::~GameScene()
{

}

void GameScene::generateAsteroids()
{
	for(int i = 0; i < 10; i++)
	{
		Asteroid *asteroid = new Asteroid(20);
		if(rand()%10<5)
		{
			asteroid->X(-20);
		}
		else
		{
			asteroid->X(SDL_GetVideoSurface()->w);
		}

		if(rand()%10<5)
		{
			asteroid->Y(-20);
		}
		else
		{
			asteroid->Y(SDL_GetVideoSurface()->h);
		}

		addEntity(asteroid);
		addRenderable(asteroid);
	}
}

void GameScene::update()
{

	Scene::update();
}
