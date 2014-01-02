#ifndef __ASTEROID_HPP__
#define __ASTEROID_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Asteroid : public Entity, public Renderable
{
public:
	Asteroid(double radius);
	~Asteroid();

	bool update();
	bool render();
	int getId();

	void hasCollided(Collidable *target);

	void destroyed();

	void entityAdded();
	void entityRemoved();
private:
	double angle;
	double rotspeed;
	int *peeks;
	double xspeed;
	double yspeed;
};

#endif
