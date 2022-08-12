#ifndef IMAGE_HPP
# define IMAGE_HPP
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

class Image
{
public:
	Image(const char *path);
	~Image();

	SDL_Surface *surface;
	SDL_Texture *texture;
};

#endif