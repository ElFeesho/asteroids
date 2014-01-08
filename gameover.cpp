#include "gameover.hpp"

#include <SDL/SDL_gfxPrimitives.h>

GameOver::GameOver()
{

}

GameOver::~GameOver()
{
	
}

void GameOver::render()
{
	// G
	aalineColor(SDL_GetVideoSurface(), 200, 100, 230, 100, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 200, 100, 200, 180, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 200, 180, 230, 180, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 230, 180, 230, 150, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 230, 150, 215, 150, 0xffffffff);

	// A
	aalineColor(SDL_GetVideoSurface(), 240, 100, 240, 180, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 240, 130, 270, 130, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 240, 100, 270, 100, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 270, 100, 270, 180, 0xffffffff);

	// M
	aalineColor(SDL_GetVideoSurface(), 280, 100, 280, 180, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 280, 100, 295, 130, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 295, 130, 310, 100, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 310, 100, 310, 180, 0xffffffff);

	// E
	aalineColor(SDL_GetVideoSurface(), 320, 100, 320, 180, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 320, 100, 350, 100, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 320, 130, 350, 130, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 320, 180, 350, 180, 0xffffffff);

	aalineColor(SDL_GetVideoSurface(), 200, 200, 200, 280, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 230, 200, 230, 280, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 200, 200, 230, 200, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 200, 280, 230, 280, 0xffffffff);

	aalineColor(SDL_GetVideoSurface(), 240, 200, 255, 280, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 270, 200, 255, 280, 0xffffffff);

	// E
	aalineColor(SDL_GetVideoSurface(), 280, 200, 280, 280, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 280, 200, 310, 200, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 280, 230, 310, 230, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 280, 280, 310, 280, 0xffffffff);

	// E
	aalineColor(SDL_GetVideoSurface(), 320, 200, 320, 280, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 320, 200, 350, 200, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 350, 200, 320, 230, 0xffffffff);
	aalineColor(SDL_GetVideoSurface(), 320, 230, 350, 280, 0xffffffff);
}