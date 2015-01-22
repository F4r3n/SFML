#include "map.h"
#include <iostream>

Map::Map(float w,float h):_width(w),_height(h){
	_sizeX = 100;
	_sizeY = 100;
	b2Vec2 gravity (0.0f, 10.0f);
	world = new b2World(gravity,true);
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
	world = map.world;
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
			int pos = 100;
			b2BodyDef groundBodyDef;
			groundBodyDef.position.Set((i*pos+100), (j*pos+100));
			b2Body* groundBody = world->CreateBody(&groundBodyDef);
			b2PolygonShape groundBox;

			groundBox.SetAsBox(_sizeX,_sizeY); 
			groundBody->CreateFixture(&groundBox, 0.0f);
		//	std::cout << groundBody->F


			_tab[std::make_pair(i,j)] = new Case(new Box(i*pos+200,_sizeX,j*pos+200,_sizeY),
					  new sf::RectangleShape(sf::Vector2f(_sizeX,_sizeY)),
					  i*pos+200,
					  j*pos+200,groundBody);

			_tab[std::make_pair(i,j)]->s->setFillColor(sf::Color::Green);
			_tab[std::make_pair(i,j)]->s->setPosition(groundBody->GetPosition().x,groundBody->GetPosition().y);	

			i=(i+1)%(int)_width;
			if(i==0) j++;

		}

	}
}


void Map::draw(sf::RenderWindow &window,float x,float y) {

	for(auto &t: _tab) {
		t.second->s->setFillColor(sf::Color::Green);
		window.draw(*t.second->s);
	}
}
