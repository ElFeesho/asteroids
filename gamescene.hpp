#ifndef __GAME_SCENE_HPP__
#define __GAME_SCENE_HPP__

#include "scene.hpp"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();

	void update();

	void generateAsteroids();
private:

};

#endif
