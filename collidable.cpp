#include "collidable.hpp"

#include <math.h>

Collidable::~Collidable()
{

}

void Collidable::checkCollision(Collidable *target)
{
	if (!target)
	{
		return;
	}

	double xdiff = (target->getX()+target->getRadius()) - (getX()+getRadius());
	double ydiff = (target->getY()+target->getRadius()) - (getY()+getRadius());
	xdiff *= xdiff;
	ydiff *= ydiff;
	double radius = getRadius()+target->getRadius();

	if(sqrt(xdiff + ydiff) < radius)
	{
		this->hasCollided(target);
		target->hasCollided(this);
	}
}

void Collidable::hasCollided(Collidable *victim)
{

}
