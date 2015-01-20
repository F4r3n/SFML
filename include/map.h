#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include <unistd.h>
#include "box.h"
#include "case.h"

class Map {
	public:
		Map(float w,float h);
		Map();
		Map& operator=(const Map &map);
		~Map();
		void load(const std::string &name);
		void save();
		void draw(sf::RenderWindow &window,float x,float y);
		std::map<std::pair<int,int>,Case*> getTab();
	private:
		float _width;
		float _height;
		std::map<std::pair<int,int>,Case*> _tab;
		float _sizeX;
		float _sizeY;


};

#endif
