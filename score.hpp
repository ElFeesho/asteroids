#ifndef __SCORE_HPP__
#define __SCORE_HPP__

#include "number.hpp"
#include "entity.hpp"

class Score : public Entity, public Number
{
public:
	Score();
	~Score();

	bool update();
	int getId();

	void addPoints(int points);

private:
	int points;
};

#endif
