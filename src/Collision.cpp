#include "Collision.hpp"

Collision::Collision(Vector2 size, Vector2 *pos)
{
	this->size.x = size.x;
	this->size.y = size.y;
	this->pos = pos;
}

void Collision::setSize(Vector2 size)
{
	this->size = size;
}

Collision::conflict Collision::IsConflict(std::vector <GameObject *>*OtherObjets)
{
	//	Karşılaştırma değişkenleri
	Vector2 This_BeginEnd[2];
	Vector2 Other_BeginEnd[2];
	//	x_BeginEnd[0].x = left
	//	x_BeginEnd[1].x = right
	//	x_BeginEnd[0].y = up
	//	x_BeginEnd[1].y = down

	// (This)Objenin Collision'unun başladığı[0] ve bittiği[1] noktalar.
	This_BeginEnd[0].x = this->pos->x;
	This_BeginEnd[1].x = this->pos->x + this->size.x;
	This_BeginEnd[0].y = this->pos->y;
	This_BeginEnd[1].y = this->pos->y + this->size.y;

	for (auto &objets : *OtherObjets)
	{
		// (object)Objenin Collision'unun başladığı[0] ve bittiği[1] noktalar.
		Other_BeginEnd[0].x = objets->OBJ_Collision.pos->x;
		Other_BeginEnd[1].x = objets->OBJ_Collision.size.x + Other_BeginEnd[0].x;
		Other_BeginEnd[0].y = objets->OBJ_Collision.pos->y;
		Other_BeginEnd[1].y = objets->OBJ_Collision.size.y + Other_BeginEnd[0].y;

		// Projemizdeki objeler birbirinin üstüne çıkmaya çalıştığı için
		// ilk önce UP/DOWN durumlarını kontrol ediyoruz
		if (This_BeginEnd[0].y <= Other_BeginEnd[1].y)//		* this.up <= other.down
		{
			return (up);
		}
		else if (This_BeginEnd[1].y >= Other_BeginEnd[0].y)//	* this.down <= other.up
		{
			return (down);
		}
		else if (This_BeginEnd[0].x <= Other_BeginEnd[1].x)//	* this.left <= other.right
		{
			return (left);
		}
		else if (This_BeginEnd[1].x >= Other_BeginEnd[0].x)//	* this.right <= other.left
		{
			return (right);
		}
	}
}

bool Collision::IsConflict(std::vector <GameObject *>*OtherObjets, conflict direction)
{
	// Karşılaştıma değişkenleri
	Vector2 This_BeginEnd[2];
	Vector2 Other_BeginEnd[2];
	//	x_BeginEnd[0].x = left
	//	x_BeginEnd[1].x = right
	//	x_BeginEnd[0].y = up
	//	x_BeginEnd[1].y = down

	// (This)Objenin Collision'unun başladığı[0] ve bittiği[1] noktalar.
	This_BeginEnd[0].x = this->pos->x;
	This_BeginEnd[1].x = this->pos->x + this->size.x;
	This_BeginEnd[0].y = this->pos->y;
	This_BeginEnd[1].y = this->pos->y + this->size.y;

	//
	//	TODO : kod şuanda çalışır ama daha sonra directionlar kontrol edilirken
	//	Objenin ortasına kadar bakıcak daha fazlası ile ilgilenmicek
	//

	if (direction == left)//		* Looks for only left
	{
		for (auto &objets : *OtherObjets)
		{
			Other_BeginEnd[1].x = objets->OBJ_Collision.pos->x + objets->OBJ_Collision.size.x;
			if (This_BeginEnd[0].x <= Other_BeginEnd[1].x)
			{
				return (true);
			}
		}
	}
	else if (direction == right)//	* Looks for only right
	{
		for (auto &objets : *OtherObjets)
		{
			Other_BeginEnd[0].x = objets->OBJ_Collision.pos->x;
			if (This_BeginEnd[1].x >= Other_BeginEnd[0].x)
			{
				return (true);
			}
		}
	}
	else if (direction == up)//		* Looks for only up
	{
		for (auto &objets : *OtherObjets)
		{
			Other_BeginEnd[1].y = objets->OBJ_Collision.pos->y + objets->OBJ_Collision.size.x;
			if (This_BeginEnd[0].y <= Other_BeginEnd[1].y)
			{
				return (true);
			}
		}
	}
	else if (direction == down)//	* Looks for only down
	{
		for (auto &objets : *OtherObjets)
		{
			Other_BeginEnd[0].y = objets->OBJ_Collision.pos->y;
			if (This_BeginEnd[1].y >= Other_BeginEnd[0].y)
			{
				return (true);
			}
		}
	}
	return (false);
}
