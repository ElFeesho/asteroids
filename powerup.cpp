#include "powerup.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "engine.hpp"

#define LIFE_TIME 5000

#include "ship.hpp"

PowerUp::PowerUp(int type) : type(type), birthTime(SDL_GetTicks())
{
	X((rand()%SDL_GetVideoSurface()->w - 60) + 30);
	Y((rand()%SDL_GetVideoSurface()->h - 60) + 30);
	setRadius(18);
}

PowerUp::~PowerUp()
{

}

void PowerUp::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void PowerUp::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

int PowerUp::getId()
{
	return type;
}

bool PowerUp::update()
{
	if(SDL_GetTicks()>birthTime+LIFE_TIME)
	{
		kill();
	}
	return isAlive();
}

bool PowerUp::render()
{
	double throughLife = (double)(SDL_GetTicks()-birthTime)/(double)LIFE_TIME;
	int color = (double)0xff * throughLife;
	int end = (1.0f-throughLife)*360.0f;
	arcRGBA(SDL_GetVideoSurface(), X(), Y(), getRadius(), 0, end, 0xff, 0xff, 0xff, 0xff-color);
	if(type == 10)
	{
		// Spray power up
		filledCircleRGBA(SDL_GetVideoSurface(), X()-10, Y()+3, 4, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X(), Y()-3, 4, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X()+10, Y()+3, 4, 0xff, 0xff, 0xff, 0xff-color);
	}
	else if(type == 11)
	{
		// Cluster bullet
		filledCircleRGBA(SDL_GetVideoSurface(), X(), Y(), 4, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X()-10, Y()-4, 2, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X(), Y()-8, 2, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X()+10, Y()-4, 2, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X()-8, Y()+6, 2, 0xff, 0xff, 0xff, 0xff-color);
		filledCircleRGBA(SDL_GetVideoSurface(), X()+8, Y()+6, 2, 0xff, 0xff, 0xff, 0xff-color);
		
	}
	else if(type == 12)
	{
		// Shield
		aacircleColor(SDL_GetVideoSurface(), X(), Y(), getRadius()-10+(cos((double)SDL_GetTicks()/100.0f)*3), 0xffffffff);
	}
	return isAlive();
}

void PowerUp::hasCollided(Collidable *target)
{
	if(target->getId() == 0) // Hit the ship- imbue the new powerup
	{
		Ship *ship = (Ship*)target;
		if(type == 10)
		{
			ship->enableTriShot();
		}
		else if(type == 11)
		{
			ship->enableClusterShot();
		}
		else if(type == 12)
		{
			ship->enableShield();
		}
		kill();
	}
}