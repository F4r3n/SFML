#include "map.h"
#include <iostream>

Map::Map(float w,float h):_width(w),_height(h){
}

Map::~Map() {
}

void Map::load(const std::string &name) {
	std::string path = "assets/"+name;
	if(access(path.c_str(),F_OK)!=-1) {
		std::fstream file(path);
		int tile=0;
		int i=0;
		int j=0;

		while(file >> tile) {
			std::cout << i <<" " <<j <<std::endl;
			
			_tab[std::make_pair(i,j)] = tile;

			i=(i+1)%(int)_width;
			if(i==0) j++;
		}
	}
}


void Map::draw(sf::RenderWindow &window) {

}
