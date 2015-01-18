#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include <unistd.h>


class Map {
	public:
		Map(float w,float h);
		Map();
		Map& operator=(const Map &map);
		~Map();
		void load(const std::string &name);
		void save();
		void draw(sf::RenderWindow &window,float x,float y);
	private:
		float _width;
		float _height;
		std::map<std::pair<int,int>,sf::Shape*> _tab;

};

#endif
