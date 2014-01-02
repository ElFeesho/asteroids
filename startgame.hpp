#ifndef __STARTGAME_HPP__
#define __STARTGAME_HPP__

#include "scene.hpp"


#include "number.hpp"

class StartGame : public Scene
{
public:
	StartGame();
	~StartGame();

	void render();
	void update();

private:
	Number *scoreIndicator;
};

#endif
