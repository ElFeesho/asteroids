#ifndef __BULLET_HPP__
#define __BULLET_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Bullet : public Entity, public Renderable
{
public:
	Bullet(double angle, double x, double y);
	~Bullet();

	bool render();
	bool update();

	int getId();

	void entityAdded();
	void entityRemoved();

private:
	double angle;
	long birthTime;
};

#endif
