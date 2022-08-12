# include <SDL2/SDL_image.h>

#include "Image.hpp"
#include "Global.hpp"

Image::Image(const char *path)
{
	SDL_Surface *s = IMG_Load(path);
	surface = SDL_ConvertSurface(s, win->screenSurface->format, 0);
	texture = SDL_CreateTextureFromSurface(win->renderer, s);
	SDL_FreeSurface(s);
}

Image::~Image()
{
	SDL_FreeSurface(surface);
}