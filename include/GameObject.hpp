#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <string>
#include "Vector.hpp"
#include "Image.hpp"

using std::string;

class GameObject
{
private:
	void updateRect();

	SDL_Rect rect;

public:
	GameObject(Vector2 pos, Vector2 size, Image *img, string *name);
	void SetPosition(int x, int y);
	void Render();

	Vector2 pos;
	Vector2 size;
	Image *image;
	string *name;
};

#endif