#ifndef BOX_H
#define BOX_H

#include <map>
#include <algorithm>

class Box {
	public:
		Box(float x,float w, float y, float h);
		float getCenterX();
		float getCenterY();
		int direction(Box *b);

		~Box();
		bool AABB(Box *b);
		float x,w,y,h;
		

};


#endif
