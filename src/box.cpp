#include "box.h"
#include <iostream>
Box::Box(float x,float w, float y, float h) : x(x), w(w),y(y),h(h) {

}

Box::Box() {

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

int Box::direction(Box *bo) {
	int i=0;
	std::vector<Box> _sideBox;
	int b = 3;

	_sideBox.push_back(Box(x+1,b,y+b,h-2*b));
	_sideBox.push_back(Box(x+w-b-1,b,y+b,h-2*b));
	_sideBox.push_back(Box(x+b,w-b*2,y+1,b));
	_sideBox.push_back(Box(x+b,w-b*2,y+h-b-1,b));
	for(auto s : _sideBox) {
		if(s.AABB(bo)) return i;
		i++;
	}
	return -1;

}
