#include <SFML/Graphics.hpp>
#include "level.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape *shape = new sf::CircleShape(100.0f);
    shape->setFillColor(sf::Color::Green);
	Level l(0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
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
