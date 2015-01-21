#ifndef CASE_H
#define CASE_H

#include "box.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


class Case {
	public:
		Case(Box *b,sf::Shape *s,float x,float y,b2Body* groundBody );
		Box *box;
		sf::Shape *s;
		float x,y;
		b2Body* groundBody; 
};

#endif
