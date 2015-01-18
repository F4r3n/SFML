#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "map.h"

class Entity {
	public:
		Entity(Map *map);
		virtual ~Entity()=0;
		virtual sf::Shape* draw()=0;
		virtual bool isAlive()=0;
		virtual void update(float dt) = 0;
		virtual float getX() = 0;
		virtual float getY() = 0;

	protected:
		float _x,_y;
		float _dx,_dy;
		Map *_map;


};

#endif
