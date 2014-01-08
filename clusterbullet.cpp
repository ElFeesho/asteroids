#include "clusterbullet.hpp"

#include "engine.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

ClusterBullet::ClusterBullet(double angle, double x, double y) : Bullet(angle, x, y)
{

}

ClusterBullet::~ClusterBullet()
{

}

void ClusterBullet::hitAsteroid()
{
	double angleStep = (M_PI*2)/5;
	for(int i = 0; i < 5; i++)
	{
		Bullet *bullet = new Bullet(i*angleStep, X(), Y());
		Engine::getInstance()->getActiveScene()->addEntity(bullet);
	}
}