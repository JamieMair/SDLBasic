#pragma once

#include <SDL.h>

class Game
{
public:
	Game(SDL_Surface* surface, SDL_Window* game_window);
	~Game();

	void Update(float elapsed_time);
	void Draw();

private:
	SDL_Surface* screen_surface;
	SDL_Window* window;
};

