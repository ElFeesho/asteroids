#include "shrapnel.hpp"

#include "engine.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

Shrapnel::Shrapnel(double angle, double x, double y, double xspeed, double yspeed) : angle(angle), xspeed(xspeed), yspeed(yspeed)
{
	X(x);
	Y(y);
	colour = 0x0088ffff;
	rotspeed = rand()%10>5?0.1:-0.1;
	livetime = SDL_GetTicks()+500;

	size = 5 + ((rand()%20))-10;
}

Shrapnel::~Shrapnel()
{

}

void Shrapnel::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void Shrapnel::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

bool Shrapnel::update()
{
	X(X()+cos(angle)*xspeed);
	Y(Y()+sin(angle)*yspeed);
	rotation += rotspeed;
	if(SDL_GetTicks()>livetime)
	{
		colour -= 0x0088ffff/7;
	}
	if(colour == 0)
	{
		kill();
	}
	return isAlive();
}

bool Shrapnel::render()
{
	aalineColor(SDL_GetVideoSurface(), X()+cos(rotation)*size, Y()+sin(rotation)*size, X()-cos(rotation)*size, Y()-sin(rotation)*size, colour);
	return isAlive();
}

int Shrapnel::getId()
{
	return -1;
}