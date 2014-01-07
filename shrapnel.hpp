#ifndef __SHRAPNEL_HPP__
#define __SHRAPNEL_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class Shrapnel : public Entity, public Renderable
{
public:
	Shrapnel(double angle, double x, double y, double xspeed, double yspeed);
	~Shrapnel();

	bool update();
	bool render();

	int getId();

	void entityAdded();
	void entityRemoved();
private:
	double angle;
	double xspeed;
	double yspeed;
	double rotation;
	double rotspeed;
	int colour;
	long livetime;
	int size;
};

#endif