#include <iostream>
#include <SDL.h>
#include <ctime>
#include "Game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

double previous_time;
double current_time;

int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screen_surface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);


			previous_time = double(clock());
			float elapsed_time = 0;
			SDL_Event evt;
			bool programrunning = true;
			Game* game = new Game(screen_surface, window);

			while (programrunning)
			{
				while (SDL_PollEvent(&evt))
				{
					switch (evt.type)
					{
					case SDL_QUIT:  programrunning = false;   break;
						/* process other events you want to handle here */
					}
				}
				// Reset the new time
				current_time = double(clock());
				elapsed_time = float((current_time - previous_time) / CLOCKS_PER_SEC);

				// Update the game
				game->Update(elapsed_time);

				// Draw the scene
				game->Draw();



				previous_time = current_time;
			}
			delete game;
			//Wait two seconds
			SDL_Delay(20);
		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}