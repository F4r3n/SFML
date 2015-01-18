#include "map.h"
#include <iostream>

Map::Map(float w,float h):_width(w),_height(h){
}

Map::Map() {

}

Map::~Map() {
}

Map& Map::operator=(const Map &map) {
	if(this == &map) return *this;
	_width=map._width;
	_height=map._height;
	_tab=map._tab;
	return *this;

}


void Map::load(const std::string &name) {
	std::string path = "assets/"+name;
	if(access(path.c_str(),F_OK)!=-1) {
		std::fstream file(path);
		int tile=0;
		int i=0;
		int j=0;

		while(file >> tile) {
			_tab[std::make_pair(i,j)] = new sf::CircleShape(20.0f);
			i=(i+1)%(int)_width;
			if(i==0) j++;
		}
	}
}


void Map::draw(sf::RenderWindow &window,float x,float y) {

	for(auto c: _tab) {
		c.second->setFillColor(sf::Color::Green);
		c.second->setPosition(100+c.first.first*100-x,100+c.first.second*100-y);
		window.draw(*c.second);
	}
}
