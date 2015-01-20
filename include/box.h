#ifndef BOX_H
#define BOX_H

#include <vector>
#include <algorithm>

class Box {
	public:
		Box(float x,float w, float y, float h);
		Box();
		float getCenterX();
		float getCenterY();
		int direction(Box *bo);

		~Box();
		bool AABB(Box *b);
		float x,w,y,h;
	private:
		

};


#endif
