#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include <math.h>

#include "engine.hpp"
#include "startscene.hpp"

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Surface *screen = SDL_SetVideoMode(1366, 768, 0, SDL_SWSURFACE|SDL_FULLSCREEN);

	int done = 0;
	SDL_Event event;
	long delay = 0;
	long start = 0;

	srand(time(NULL));

	Engine *engine = Engine::getInstance();

	engine->pushScene(new StartScene());

	while (!done)
	{
		start = SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				done = 1;
			}
			else if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_ESCAPE)
				{
					done = 1;
				}
			}
		}

		SDL_FillRect(screen, NULL, 0x00000000);

		engine->update();
		engine->render();

		SDL_Flip(screen);

		delay = (1000/60) - (SDL_GetTicks()-start);
		if (delay > 0)
		{
			SDL_Delay(delay);
		}
	}

	Engine::shutdown();

	SDL_FreeSurface(screen);

	SDL_Quit();
	return 0;
}
