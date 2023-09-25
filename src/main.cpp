#include <iostream>
#include <SDL2/SDL.h>

#include "../physics/include/verlet_solver.hpp"
#include "../physics/include/moving_object.hpp"

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Error initializing SDL : " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("RenderTests",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
	800, 600, 
	0);
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::cout << "Hello there" << std::endl;

	zps::VerletSolver solver;
	zps::MovingObject object;
	solver.addObject(object);
	object.pos = object.pos + 1;

	SDL_Rect rect;
	rect.x = 375;
	rect.y = 175;
	rect.w = 50;
	rect.h = 50;

	bool running = true;

	while (running)
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
		}

		solver.computeFrame();
		rect.x = object.pos.x;
		rect.y = object.pos.y;
		
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}