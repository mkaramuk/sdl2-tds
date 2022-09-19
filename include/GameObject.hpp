#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector.hpp"
#include "Image.hpp"

using std::string;

class GameObject;

class Collision
{
public:
	enum conflict
	{
		up,
		down,
		right,
		left,
		none
	};
	Collision();
	Collision(Vector2 size, Vector2 *pos);
	void setSize(Vector2 size);
	conflict IsConflict(std::vector<GameObject *> *OtherObjets);
	bool IsConflict(std::vector<GameObject *> *OtherObjets, conflict direction); // TODO
	~Collision();

private:
	Vector2 size;
	Vector2 *pos;
};

class GameObject
{
private:
	void updateRect();

	SDL_Rect rect;

public:
	GameObject(Vector2 pos, Vector2 size, Image *img, string *name);
	void SetPosition(int x, int y);
	void Render();

	Collision OBJ_Collision;
	Vector2 pos;
	Vector2 size;
	Image *image;
	string *name;
};

#endif
