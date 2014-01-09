#include "gamescene.hpp"
#include <SDL/SDL.h>
#include "ship.hpp"
#include "asteroid.hpp"
#include "score.hpp"
#include "powerup.hpp"

GameScene::GameScene()
{
	Ship *ship = new Ship();
	Score *score = new Score();

	addEntity(ship);
	addRenderable(ship);

	addEntity(score);
	addRenderable(score);

	generateAsteroids();
	lastThink = SDL_GetTicks();
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
	}
}

void GameScene::update()
{
	if(SDL_GetTicks()>lastThink+5000)
	{
		if(rand()%100 > 75)
		{
			addEntity(new PowerUp((rand()%3) + 10));
			lastThink = SDL_GetTicks();
		}
	}
	Scene::update();
}
