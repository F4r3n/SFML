#ifndef SCREEN_H
#define SCREEN_H

#include "engine.h"

class Screen {
	public:
		virtual void update(float dt)=0;
		virtual void draw()=0;
		virtual ~Screen();
		Screen();
		void init(Engine *engine);

	private:
		Engine *_engine;

};


#endif
