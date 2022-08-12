#ifndef GAMEWINDOW_HPP
# define GAMEWINDOW_HPP
# include <SDL2/SDL.h>
# include "GameObject.hpp"

class GameWindow
{
private:


public:
	GameWindow();
	~GameWindow();
	void Render();
	void EventLoop();

	SDL_Surface *screenSurface;
	SDL_Window *window;
	SDL_Renderer *renderer;
	GameObject *gameObject;
};

#endif