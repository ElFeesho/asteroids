#include "powerup.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "engine.hpp"

#define LIFE_TIME 5000

PowerUp::PowerUp(int type) : type(type), birthTime(SDL_GetTicks())
{
	X((rand()%SDL_GetVideoSurface()->w - 60) + 30);
	Y((rand()%SDL_GetVideoSurface()->h - 60) + 30);
	setRadius(15);
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

	}
	else if(type == 11)
	{

	}
	else if(type == 12)
	{

	}
	return isAlive();
}