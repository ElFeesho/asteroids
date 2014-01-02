#include <SDL/SDL.h>

#include "startgame.hpp"

#include "engine.hpp"

#include "gamescene.hpp"

StartGame::StartGame()
{
	SDL_Surface *screen = SDL_GetVideoSurface();

	scoreIndicator = new Number();
}

StartGame::~StartGame()
{

}

void StartGame::update()
{
	Uint8 *keys = SDL_GetKeyState(NULL);
	if(keys[SDLK_SPACE])
	{
		Engine::getInstance()->popScene();
		GameScene *gameScene = new GameScene();
		Engine::getInstance()->pushScene(gameScene);
	}
}

void StartGame::render()
{
	scoreIndicator->setNumber(1000);
	scoreIndicator->render();
}
