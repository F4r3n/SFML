#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include "map.h"
#include <vector>
#include "player.h"
#include <SFML/Graphics.hpp>
class Level {

	public:
		Level(int n);
		Level();
		Level& operator=(Level &level);
		~Level();
		void setLevel(int n);
		void draw(sf::RenderWindow &window);
		void update(float dt);


	private:
		std::vector<Entity*> _entities;
		int _n;
		Map *_map;
		sf::RenderWindow _window;

};

#endif

