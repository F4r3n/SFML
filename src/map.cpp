#include "map.h"
#include <iostream>

Map::Map(float w,float h):_width(w),_height(h){
	_sizeX = 100;
	_sizeY = 100;

}


Map::Map() {

}

Map::~Map() {
}

std::map<std::pair<int,int>,Case*> Map::getTab() {
	return _tab;
}

Map& Map::operator=(const Map &map) {
	if(this == &map) return *this;
	for(auto &t : _tab) {
		delete t.second->box;
		delete t.second->s;

		delete t.second;
	}

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
			int pos = 200;
			_tab[std::make_pair(i,j)] = new Case(new Box(i*pos+100,_sizeX,j*pos+100,_sizeY),
												 new sf::RectangleShape(sf::Vector2f(_sizeX,_sizeY)),
												 i*pos+100,
												 j*pos+100);

			i=(i+1)%(int)_width;
			if(i==0) j++;
		}
	}
}


void Map::draw(sf::RenderWindow &window,float x,float y) {

	for(auto &t: _tab) {
		t.second->s->setFillColor(sf::Color::Green);
		t.second->box->x = t.second->x-x;
		t.second->box->y = t.second->y-y;


		t.second->s->setPosition(t.second->box->x,t.second->box->y);
		window.draw(*t.second->s);
	}
}
