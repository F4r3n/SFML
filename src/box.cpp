#include "box.h"

Box::Box(float x,float w, float y, float h) : _x(x),_w(w),_y(y),_h(h) {
}

bool Box::AABB(Box b) {
	if((b._x >= _x + _w)      // trop à droite
			  || (b._x + b._w <= _x) // trop à gauche
			  || (b._y >= _y + _h) // trop en bas
			  || (b._y + b._h <= _y))  // trop en haut
		return false; 
	else
		return true; 
}
