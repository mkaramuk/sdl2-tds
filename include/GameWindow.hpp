#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "GameObject.hpp"

using std::string;

class GameWindow
{
private:
public:
	GameWindow();
	~GameWindow();
	void Render();
	void EventLoop();
	void AddGameObject(GameObject *obj);
	GameObject *FindObjectWithName(string name);

	SDL_Surface *screenSurface;
	SDL_Window *window;
	SDL_Renderer *renderer;
	std::vector<GameObject *> *gameObjects;
};

#endif