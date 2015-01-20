#include "box.h"
#include <iostream>
Box::Box(float x,float w, float y, float h) : x(x), w(w),y(y),h(h) {
	
}

Box::~Box() {

}

float Box::getCenterX() {
	return (x + w)/2;
}

float Box::getCenterY() {
	return (y + h)/2;	
}


bool Box::AABB(Box *b) {
	if((b->x >= x + w)      // trop à droite
			  || (b->x + b->w <= x) // trop à gauche
			  || (b->y >= y + h) // trop en bas
			  || (b->y + b->h <= y))  // trop en haut
		return false; 
	else
		return true; 
}

int Box::direction(Box *b) {
	std::map<int,float> dir;
	float centerX = b->getCenterX();
	float centerY = b->getCenterY();

	dir[2] = (abs((y + h)-centerY));
	dir[3] = (abs(y-centerY));
	dir[1] = (abs(x-centerX));
	dir[0] = (abs((x+w)-centerX));

	int min = 1000;
	int key = -1;
	for(auto d : dir) {
		std::cout << d.first << " " << d.second << std::endl;
		if(min > d.second) {
			min = d.second;
			key = d.first;
		}
	}
	std::cout << "\n" <<std::endl;


	return key;

}
