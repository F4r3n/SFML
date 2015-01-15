#include "player.h"

Player::Player(){
_x = 0;
_y = 0;
_box = new Box(_x,W,_y,H);
_s = new sf::CircleShape(100.0f);
}


Player::~Player() {
}

sf::Shape* Player::draw() {
	_s->setFillColor(sf::Color::White);
return _s;
}

bool Player::isAlive() {
	return true;
}
