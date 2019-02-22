#include "Game.h"


Game::Game(SDL_Surface * surface, SDL_Window* game_window) : screen_surface(surface), window(game_window)
{

}

Game::~Game()
{
}

void Game::Update(float elapsed_time)
{
}

void Game::Draw()
{

	SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0x00, 0x00, 0x00));



	SDL_UpdateWindowSurface(window);
}
