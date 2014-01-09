#ifndef __SHIP_HPP__
#define __SHIP_HPP__

#include "entity.hpp"
#include "collidable.hpp"
#include "renderable.hpp"

class Ship : public Renderable, public Entity
{
public:
	Ship();
	~Ship();

	bool update();
	bool render();

	void hasCollided(Collidable *victim);

	int getId();

	void decShotCount();

	void enableTriShot();
	void enableClusterShot();
	void enableShield();
	bool trishotEnabled();
	bool clusterShotEnabled();
	bool shieldEnabled();
private:
	double angle;
	double xspeed;
	double yspeed;

	long lastShot;
	long shotCount;

	int lives;

	long deathTime;
	bool dead;
	bool shouldRespawn;

	bool *powerUps;

	long shieldStartTime;
};

#endif
