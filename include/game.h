#ifndef GAME_H
#define GAME_H

#include "level.h"
#include "screen.h"

class Game: public Screen {

	public:
		Game();
		void update(float dt);
		void draw(sf::RenderWindow &window);
		void changeLevel();
		~Game();
	private:
		Level _level;


};

#endif
