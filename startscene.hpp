#ifndef __START_SCENE_HPP__
#define __START_SCENE_HPP__

#include "scene.hpp"

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();

	void update();
	void render();
private:
	int menuChoice;
};

#endif