#include "asteroid.hpp"
#include "score.hpp"
#include "engine.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

Asteroid::Asteroid(double radius)
{
	rotspeed = 0.04;
	setRadius(radius);
	peeks = new int[8];
	int r = getRadius()/2;
	for(int i = 0; i < 7; i++)
	{
		peeks[i] = getRadius() + ((rand()%r*2)-r);
	}
	peeks[7] = peeks[0];

	xspeed = 0.2 + rand()%1;
	xspeed *= rand()%10>5?-1.0:1.0;

	yspeed = 0.2 + rand()%1;
	yspeed *= rand()%10>5?-1.0:1.0;
}

Asteroid::~Asteroid()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

int Asteroid::getId()
{
	return 2;
}

bool Asteroid::render()
{
	double step = (M_PI*2)/8;
	int i = 0;
	int k = 1;
	for(double x = 0; x < M_PI * 2; x += step)
	{
		aalineColor(SDL_GetVideoSurface(), X() + cos(x+angle)*peeks[i], Y()+sin(x+angle)*peeks[i], X() + cos(x+step + angle)* peeks[k], Y() + sin(x +step+ angle)*peeks[k], 0x0088ffff);
		i++;
		k++;
		if(k>7)
		{
			k = 0;
		}
	}
	return isAlive();
}

bool Asteroid::update()
{
	angle += rotspeed;
	X(X()+xspeed);
	Y(Y()+yspeed);

	if(X()<0)
	{
		X(SDL_GetVideoSurface()->w);
	}
	else if(X()>SDL_GetVideoSurface()->w)
	{
		X(0);
	}

	if(Y()<0)
	{
		Y(SDL_GetVideoSurface()->h);
	}
	else if(Y()>SDL_GetVideoSurface()->h)
	{
		Y(0);
	}
	return isAlive();
}

void Asteroid::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void Asteroid::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

void Asteroid::destroyed()
{
	if(getRadius()>7)
	{
		for(int i = 0; i<4; i++)
		{
			Asteroid *newAsteroid = new Asteroid(getRadius()/2);
			newAsteroid->X(X());
			newAsteroid->Y(Y());
			Engine::getInstance()->getActiveScene()->addEntity(newAsteroid);
			Engine::getInstance()->getActiveScene()->addRenderable(newAsteroid);
		}
	}
	((Score*)Engine::getInstance()->getActiveScene()->findEntityByName("score"))->addPoints(15);
}

void Asteroid::hasCollided(Collidable *target)
{
	if(target->getId() == 1)
	{
		destroyed();

		kill();
		((Entity*)target)->kill();
	}
	else if(target->getId() == 0) // Hit the ship
	{
		destroyed();
		kill();
	}
}

