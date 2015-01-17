#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "box.h"
class Player : public Entity {
	public:
		Player();
		~Player();
		sf::Shape* draw();
		void update(float dt);
		bool isAlive();
		float getX();
		float getY();

	private:
		int _life;
		Box *_box;
		sf::Shape *_s;
		float _dx,_dy;
		float _x;
		float _y;
		float _speed = 10000;
		const float W = 20;
		const float H = 20;



};

#endif
