#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP
# include "Vector.hpp"
# include "Image.hpp"

class GameObject
{
private:
	void updateRect();

	SDL_Rect rect;

public:
	GameObject(Vector2 pos, Vector2 size, Image *img);
	void SetPosition(int x, int y);
	void Render();

	Vector2 pos;
	Vector2 size;
	Image *image;
};


#endif