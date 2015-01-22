#include "level.h"
#include <iostream>

Level::Level(int n):_n(n) {

}

Level::Level() {
	view =new sf::View();
	view->setSize(800,600);
	_map = new Map(5,2);
	_map->load("map");
	_entities.push_back(new Player(_map));
}

void Level::setLevel(int n) {
	_n =n;
}

void Level::draw(sf::RenderWindow &window) {

	window.setView(*view);

	_map->draw(window,_entities[0]->getX(),_entities[0]->getY());
	view->setCenter(_entities[0]->getX(),_entities[0]->getY());
	for (auto e : _entities) {
		sf::Shape *s = e->draw();
		window.draw(*s);
	}
}

void Level::update(float dt) {

	_map->world->Step(dt,8,3);
	for (auto e : _entities) {
		e->update(dt);
	}

}

Level& Level::operator=(Level &level) {
	if(&level == this) return *this;
	for(auto &e : _entities) delete e;
	_entities = level._entities;
	_n =level._n;
	_map = level._map;
	return *this;
}


Level::~Level() {
}
