#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include "player.h"
#include <vector>

#include <SFML/Graphics.hpp>
class Level {

	public:
		Level(int n);
		Level();
		~Level();
		void draw(sf::RenderWindow &window);
		void update(float dt);


	private:
		std::vector<Entity*> _entities;
		int _n;
		sf::RenderWindow _window;

};

#endif

