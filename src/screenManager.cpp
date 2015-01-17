#include "screenManager.h"

ScreenManager::ScreenManager() {
}

ScreenManager::~ScreenManager() {
}

Screen ScreenManager::getCurrent() {
	return _currentScreen;
}


void ScreenManager::setScreen(Screen &s) {
	_currentScreen = s;
}

void ScreenManager::draw(sf::RenderWindow &window) {
	std::vector<sf::Shape*> shapes = _currentScreen.getShapes();
	for(auto  s:shapes)
		window.draw(*s);
}


