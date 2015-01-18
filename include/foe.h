#ifndef FOE_H
#define FOE_H

#include "entity.h"

class Foe : public Entity {

	public:
		Foe();
		Foe();
		sf::shape* draw();
		isalive();
		void update(float dt);
		float getx();
		float gety();

};

#endif
