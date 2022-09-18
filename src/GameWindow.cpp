#include <iostream>
#include "GameWindow.hpp"

using std::cerr;
using std::cout;
using std::endl;

GameWindow::GameWindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cerr << "error: SDL couldn't initialized" << endl;
		return;
	}
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("Game",
							  SDL_WINDOWPOS_CENTERED,
							  SDL_WINDOWPOS_CENTERED,
							  400, 400, 0);
	screenSurface = SDL_GetWindowSurface(window);
	renderer = SDL_GetRenderer(window);
	this->gameObjects = new std::vector<GameObject *>();
}

void GameWindow::AddGameObject(GameObject *obj)
{
	this->gameObjects->push_back(obj);
}

GameObject *GameWindow::FindObjectWithName(string name)
{
	for (size_t i = 0; i < this->gameObjects->size(); i++)
		if (*this->gameObjects->at(i)->name == name)
			return (this->gameObjects->at(i));
	return (NULL);
}

void GameWindow::EventLoop()
{
	SDL_Event e;
	bool exit = false;
	GameObject *player = this->FindObjectWithName("player");

	while (!exit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit = true;
			else if (e.key.keysym.sym == SDLK_d)
				player->SetPosition(player->pos.x + 10, player->pos.y);
			else if (e.key.keysym.sym == SDLK_a)
				player->SetPosition(player->pos.x - 10, player->pos.y);
			else if (e.key.keysym.sym == SDLK_s)
				player->SetPosition(player->pos.x, player->pos.y + 10);
			else if (e.key.keysym.sym == SDLK_w)
				player->SetPosition(player->pos.x, player->pos.y - 10);
		}
		Render();
	}
}

void GameWindow::Render()
{
	SDL_RenderClear(renderer);
	for (size_t i = 0; i < this->gameObjects->size(); i++)
		this->gameObjects->at(i)->Render();
	SDL_RenderPresent(renderer);
}

GameWindow::~GameWindow()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}