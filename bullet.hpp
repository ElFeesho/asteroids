#ifndef __BULLET_HPP__
#define __BULLET_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Bullet : public Entity, public Renderable
{
public:
	Bullet(double angle, double x, double y);
	virtual ~Bullet();

	bool render();
	bool update();

	int getId();

	void entityAdded();
	void entityRemoved();

	void hasCollided(Collidable *target);
	virtual void hitAsteroid();
private:
	double angle;
	long birthTime;
};

#endif
