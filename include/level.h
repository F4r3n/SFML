#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include <vector>

#include <SFML/Graphics.hpp>
class Level {

	public:
		Level(int n);
		~Level();
		void draw(sf::RenderWindow &window);


	private:
	std::vector<Entity*> _entities;
	int _n;
	sf::RenderWindow _window;

};

#endif

