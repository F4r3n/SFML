#ifndef BOX_H
#define BOX_H

class Box {
	public:
		Box(float x,float w, float y, float h);
		~Box();
		bool AABB();
	private:
		float _x,_w,_y,_h;
		

};


#endif
