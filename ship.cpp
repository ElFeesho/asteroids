#include "ship.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "engine.hpp"

#include "bullet.hpp"

void drawShip(double angle, double x, double y, double size)
{
	double topX = x + cos(angle)*-size;
	double topY = y + sin(angle)*-size;
	double bottomRightY 	= y + sin(angle+0.5)*(size*2);
	double bottomLeftY 	= y + sin(angle+-0.5)*(size*2);
	double bottomRightX 	= x + cos(angle+0.5)*(size*2);
	double bottomLeftX 	= x + cos(angle+-0.5)*(size*2);
	double bottomY 		= y + sin(angle)*size;
	double bottomX 		= x + cos(angle)*size;
	aalineColor(SDL_GetVideoSurface(), topX, topY, bottomRightX, bottomRightY, 0x0088ffff);
	aalineColor(SDL_GetVideoSurface(), topX, topY, bottomLeftX, bottomLeftY, 0x0088ffff);
	aalineColor(SDL_GetVideoSurface(), bottomRightX, bottomRightY, bottomX, bottomY, 0x0088ffff);
	aalineColor(SDL_GetVideoSurface(), bottomLeftX, bottomLeftY, bottomX, bottomY, 0x0088ffff);
}

Ship::Ship() : angle(0), xspeed(0), yspeed(0),  lastShot(0), shotCount(0), lives(3)
{
	setRadius(5);
	SDL_Surface *screen = SDL_GetVideoSurface();
	X(SDL_GetVideoSurface()->w/2-getRadius());
	Y(SDL_GetVideoSurface()->h/2-getRadius());
	xspeed = 0;
	yspeed = 0;
	angle = (M_PI*2)/4;
	setName("ship");

}

Ship::~Ship()
{

}

bool Ship::update()
{
	SDL_Surface *screen = SDL_GetVideoSurface();

	Uint8 *keystate = SDL_GetKeyState(NULL);
	if(keystate[SDLK_LEFT])
	{
		angle -= 0.1;
	}
	if(keystate[SDLK_RIGHT])
	{
		angle+=0.1;
	}

	if(keystate[SDLK_UP])
	{
		double xd = cos(angle)*-0.1;
		double yd = sin(angle)*-0.1;
		if(abs(xspeed+xd) < 15)
		{
			xspeed += xd;
		}

		if(abs(yspeed+yd) < 15)
		{
			yspeed += yd;
		}
	}

	X(X()+xspeed);
	Y(Y()+yspeed);

	double x = X();
	double y = Y();
	SDL_Surface *target = SDL_GetVideoSurface();
	if(x > target->w)
	{
		X(0);
	}
	else if(x < 0)
	{
		X(target->w);
	}

	if(y > target->h)
	{
		Y(0);
	}
	else if(y < 0)
	{
		Y(target->h);
	}


	if(keystate[SDLK_SPACE] && SDL_GetTicks() > lastShot+100 && shotCount<5)
	{
		Bullet *bullet = new Bullet(angle, X(), Y());

		Engine::getInstance()->getActiveScene()->addEntity(bullet);
		Engine::getInstance()->getActiveScene()->addRenderable(bullet);

		lastShot = SDL_GetTicks();
		shotCount++;
	}


	return isAlive();
}

int Ship::getId()
{
	return 0;
}

void Ship::decShotCount()
{
	shotCount--;
	if(shotCount < 0)
	{
		shotCount = 0;
	}
}

bool Ship::render()
{
	drawShip(angle, X(), Y(), 5);

	// Draw live indicators
	for(int i = 0; i<lives; i++)
	{
		drawShip((M_PI*2)/4, 10 + i*10, 30, 4);
	}

	return isAlive();
}

void Ship::hasCollided(Collidable *with)
{
	if(with->getId() == 2) // Hit an asteroid
	{
		lives--;
		X(SDL_GetVideoSurface()->w/2-getRadius());
		Y(SDL_GetVideoSurface()->h/2-getRadius());
		xspeed = 0;
		yspeed = 0;
		angle = (M_PI*2)/4;
	}
}
