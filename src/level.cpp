#include "level.h"
#include <iostream>

Level::Level(int n):_n(n) {
}

Level::Level() {

	_entities.push_back(new Player());
}

void Level::setLevel(int n) {
	_n =n;
}

void Level::draw(sf::RenderWindow &window) {
	for (auto e : _entities) {
		sf::Shape *s = e->draw();
		window.draw(*s);
	}
}
void Level::update(float dt) {

	for (auto e : _entities) {
		e->update(dt);
	}

}
Level::~Level() {
	/*	for(auto &e : _entities)
		delete e;*/
}
