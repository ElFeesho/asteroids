#include "shrapnel.hpp"

#include "engine.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

Shrapnel::Shrapnel(double angle, double x, double y, double xspeed, double yspeed, int colour) : angle(angle), xspeed(xspeed), yspeed(yspeed), colour(colour), alpha(255)
{
	X(x);
	Y(y);
	rotspeed = rand() % 10 > 5 ? 0.1 : -0.1;
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
		long past = SDL_GetTicks()-livetime;
		alpha = (1.0f-((double)past/1000.f))*255.f;
		
	}
	if(alpha<=0)
	{
		kill();
	}
	return isAlive();
}

bool Shrapnel::render()
{
	aalineRGBA(SDL_GetVideoSurface(), X()+cos(rotation)*size, Y()+sin(rotation)*size, X()-cos(rotation)*size, Y()-sin(rotation)*size, (colour&0xff000000)>>24, (colour&0x00ff0000)>>16, (colour&0x0000ff00)>>8, alpha);
	return isAlive();
}

int Shrapnel::getId()
{
	return -1;
}