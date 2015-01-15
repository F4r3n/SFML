#ifndef LEVEL_H
#define LEVEL_H

#include "entity.h"
#include <vector>

class Level {

	public:
		Level(int n);
		~Level();
		void draw();


	private:
	std::vector<Entity*> _entities;
	int _n;

};

#endif

