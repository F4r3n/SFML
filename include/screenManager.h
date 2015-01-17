#ifndef SCREEN_MANAGER
#define SCREEN_MANAGER

#include "screen.h"
#include <vector>
#include <SFML/Graphics.hpp>

class ScreenManager {
	public:
		ScreenManager();
		~ScreenManager();
		Screen getCurrent();
		void setScreen(Screen &s);
		void draw(sf::RenderWindow &window);
	private:
		Screen _currentScreen;

};

#endif
