#ifndef ENTITY_H
#define ENTITY_H

class Entity {
	public:
		virtual ~Entity()=0;
		virtual void draw()=0;
		virtual bool isAlive()=0;

};

#endif
