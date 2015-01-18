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
	_shapes = map._shapes;
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
			_tab[std::make_pair(i,j)] = new Box(i*40,20,j*40,20);
			i=(i+1)%(int)_width;
			if(i==0) j++;
		}
		for(auto t : _tab) {
			sf::Shape *r = new sf::RectangleShape(sf::Vector2f(t.second->w,t.second->h));
			_shapes[t.second] = r;
		}
	}
}


void Map::draw(sf::RenderWindow &window,float x,float y) {

	for(auto s: _shapes) {
		s.second->setFillColor(sf::Color::Green);
		s.second->setPosition(s.first->x+100-x,s.first->y+100-y);
		window.draw(*s.second);
	}
}
