// GBEmu.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <SDL.h>
#include "CPU.h"
#define fps 60

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = nullptr; 

	window = SDL_CreateWindow("GBemu",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1024, 512,
		SDL_WINDOW_RESIZABLE);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_RenderSetLogicalSize(renderer, 1024, 512);

	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);


	Uint32 start_tick;
	SDL_Event event;

	CPU gb_cpu = new CPU();

	bool running = true;

	while(running)
	{
		start_tick = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{

			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:

				break;
			case SDL_KEYUP:

				break;
			}
		}

		if ((1000 / fps) > SDL_GetTicks() - start_tick)
		{
			SDL_Delay(1000 / fps - (SDL_GetTicks() - start_tick));
		}
	}

	return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
