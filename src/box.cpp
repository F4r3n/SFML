#include "box.h"

Box::Box(float x,float w, float y, float h) : x(x), w(w),y(y),h(h) {
}

Box::~Box() {

}

bool Box::AABB(Box b) {
	if((b.x >= x + w)      // trop à droite
			  || (b.x + b.w <= x) // trop à gauche
			  || (b.y >= y + h) // trop en bas
			  || (b.y + b.h <= y))  // trop en haut
		return false; 
	else
		return true; 
}
