#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "box.h"
class Player : public Entity {
	public:
		Player();
		~Player();
		sf::Shape* draw();
		bool isAlive();

	private:
		int _life;
		Box *_box;
		sf::Shape *_s;
		float _x;
		float _y;
		const float W = 100;
		const float H = 100;



};

#endif
