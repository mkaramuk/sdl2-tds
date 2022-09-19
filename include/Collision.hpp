#ifndef COLLISION_HPP
# define COLLISION_HPP
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <vector>
# include "Vector.hpp"
# include "GameObject.hpp"

class Collision
{
public:
	enum conflict {up, down, right, left};
	Collision(Vector2 size, Vector2 *pos);
	void setSize(Vector2 size);
	conflict IsConflict(std::vector <GameObject *>*OtherObjets);
	bool IsConflict(std::vector <GameObject *>*OtherObjets, conflict direction); // TODO
	~Collision();

private:
	Vector2 size;
	Vector2 *pos;
};

#endif
