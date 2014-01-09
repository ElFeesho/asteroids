#include "startscene.hpp"

#include "gamescene.hpp"
#include "engine.hpp"

#include <SDL/SDL_gfxPrimitives.h>

StartScene::StartScene() : menuChoice(0)
{

}

StartScene::~StartScene()
{

}

void StartScene::update()
{
	Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_DOWN])
	{
		menuChoice = 1;
	}
	else if(keys[SDLK_UP])
	{
		menuChoice = 0;
	}
	else if(keys[SDLK_RETURN])
	{
		Engine::getInstance()->popScene();
		Engine::getInstance()->pushScene(new GameScene());
	}
	Scene::update();
}

void StartScene::render()
{
	SDL_Surface *target = SDL_GetVideoSurface();
	stringColor(target, target->w/2-50, target->h/2, "1 Player", 0xffffffff);
	stringColor(target, target->w/2-50, target->h/2+20, "2 Player", 0xffffffff);
	filledCircleColor(target, target->w/2-80, target->h/2+menuChoice*20, 5, 0xffffffff);
	Scene::render();
}