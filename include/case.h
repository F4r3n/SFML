#ifndef CASE_H
#define CASE_H

#include "box.h"
#include <SFML/Graphics.hpp>


class Case {
	public:
		Case(Box *b,sf::Shape *s,float x,float y);
		Box *box;
		sf::Shape *s;
		float x,y;

};

#endif
