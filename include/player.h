#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "Box.h"
class Player : public Entity {
	public:
		Player();
		~Player();
		sf::Shape* draw();
		bool isAlive();

	private:
		int _life;
		Box _box;



};

#endif
