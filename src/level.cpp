#include "level.h"

Level::Level(int n):_n(n) {

}

void Level::draw() {
	for (auto e : _entities)
		e->draw();
}
