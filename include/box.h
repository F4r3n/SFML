#ifndef BOX_H
#define BOX_H

class Box {
	public:
		Box(float x,float w, float y, float h);
		~Box();
		bool AABB(Box b);
		float x,w,y,h;
		

};


#endif
