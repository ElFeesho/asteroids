#include "bullet.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "engine.hpp"
#include "ship.hpp"

Bullet::Bullet(double angle, double x, double y) : angle(angle)
{
	X(x);
	Y(y);
	birthTime = SDL_GetTicks();
	setRadius(3);
	setName("bullet");
}

Bullet::~Bullet()
{
	((Ship*)Engine::getInstance()->getActiveScene()->findEntityByName("ship"))->decShotCount();
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}

bool Bullet::render()
{
	aalineColor(SDL_GetVideoSurface(), X(), Y(), X()+cos(angle)*-5, Y()+sin(angle)*-5, 0x0088ffff);
	return isAlive();
}

bool Bullet::update()
{
	X(X()+cos(angle)*-5);
	Y(Y()+sin(angle)*-5);
	if(SDL_GetTicks() > birthTime + 1000)
	{
		kill();
	}
	return isAlive();
}

int Bullet::getId()
{
	return 1;
}

void Bullet::entityAdded()
{
	Engine::getInstance()->getActiveScene()->addRenderable(this);
}

void Bullet::entityRemoved()
{
	Engine::getInstance()->getActiveScene()->removeRenderable(this);
}
