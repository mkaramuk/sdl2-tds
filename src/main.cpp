#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include "GameWindow.hpp"

GameWindow *win = new GameWindow();

int main()
{
	win->gameObject = new GameObject({ 100, 100 }, { 50, 75 }, new Image("./images/sonic.png"));
	win->EventLoop();
	return (0);
}