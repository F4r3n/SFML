#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "box.h"

class Player : public Entity {
	public:
		Player(Map *map);
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
		float _speed = 10000;
		const float W = 40;		
		const float H = 40;
		b2Body* body;



};

#endif
