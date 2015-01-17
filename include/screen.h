#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
class Screen{

	public:
		Screen();
		~Screen();
		std::vector<sf::Shape*> getShapes();	
	private:
		std::vector<sf::Shape*> _s;

};


#endif
