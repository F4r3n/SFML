#include "level.h"

Level::Level(int n):_n(n) {

}

void Level::draw(sf::RenderWindow &window) {
	for (auto e : _entities) {
		sf::Shape *s = e->draw();
		window.draw(*s);
	}
}
