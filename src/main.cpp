#include <SFML/Graphics.hpp>
#include "level.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape *shape = new sf::CircleShape(100.0f);
    shape->setFillColor(sf::Color::Green);
	Level l(0);
	sf::Clock clock;

    while (window.isOpen())
    {

		sf::Time frameTime = clock.restart();
        sf::Event event;

		float dt = frameTime.asSeconds()/10.f;
		l.update(dt);	
        while (window.pollEvent(event))
        {

	//	std::cout << "dt " << dt <<std::endl; 
	
            if (event.type == sf::Event::Closed) {
                window.close();
			}
        }

        window.clear();
        window.draw(*shape);
		l.draw(window);
        window.display();
    }

    return 0;
}
