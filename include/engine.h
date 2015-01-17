#ifndef ENGINE_H
#define ENGINE_H

#include "screen.h"
#include "game.h"
#include <SFML/Graphics.hpp>

class Engine {

	public:
		void run();
		void setScreen(Screen *screen);
		void draw(sf::RenderWindow &window);
		void update(float dt);
		void init();
		Engine();

	private:
		bool running = false;
		Screen *_screen;
};

#endif
