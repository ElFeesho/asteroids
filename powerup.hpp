#ifndef __POWERUP_HPP__
#define __POWERUP_HPP__

#include "entity.hpp"
#include "renderable.hpp"

class PowerUp : public Entity, public Renderable
{
public:
	PowerUp(int type);
	~PowerUp();

	bool update();
	bool render();

	int getId();

	void entityAdded();
	void entityRemoved();

	void hasCollided(Collidable *target);

private:
	int type;
	long birthTime;	
};

#endif