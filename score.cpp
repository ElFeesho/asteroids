#include "score.hpp"

Score::Score() : points(0)
{
	setName("score");
	X(0);
	Y(0);
}

Score::~Score()
{

}

bool Score::update()
{
	setPosition(X(), Y());
	setNumber(points);
	return true;
}

void Score::addPoints(int points)
{
	this->points+= points;
}

int Score::getId()
{
	return 5;
}
