#ifndef __CLUSTERBULLET_HPP__
#define __CLUSTERBULLET_HPP__

#include "bullet.hpp"

class ClusterBullet : public Bullet
{
public:
	ClusterBullet(double angle, double x, double y);
	~ClusterBullet();

	void hitAsteroid();
};

#endif