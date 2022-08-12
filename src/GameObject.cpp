#include "GameObject.hpp"
#include "Global.hpp"

GameObject::GameObject(Vector2 pos, Vector2 size, Image *img)
{
	this->pos = pos;
	this->size = size;
	updateRect();
	image = img;
}

void GameObject::SetPosition(int x, int y)
{
	pos.x = x;
	pos.y = y;
	updateRect();
}

void GameObject::updateRect()
{
	rect = {
		pos.x,
		pos.y,
		size.x,
		size.y
	};
}

void GameObject::Render()
{
	SDL_RenderCopy(win->renderer, image->texture, NULL, &rect);
}