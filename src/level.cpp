#include "level.h"
#include <iostream>

Level::Level(int n):_n(n) {
	
}

Level::Level() {
	_map = new Map(5,2);
	_map->load("map");
	_entities.push_back(new Player(_map));
}

void Level::setLevel(int n) {
	_n =n;
}

void Level::draw(sf::RenderWindow &window) {
	_map->draw(window,_entities[0]->getX(),_entities[0]->getY());
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

Level& Level::operator=(Level &level) {
	if(&level == this) return *this;
	_entities = level._entities;
	_n =level._n;
	_map = level._map;
	return *this;
}


Level::~Level() {
}
