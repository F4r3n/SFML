#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
class Entity {
	public:
		virtual ~Entity()=0;
		virtual sf::Shape* draw()=0;
		virtual bool isAlive()=0;

};

#endif
