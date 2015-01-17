#include "player.h"
#include <iostream>

Player::Player(){
	_x = 100;
	_y = 100;
	_dx = 0;
	_dy = 0;
	_box = new Box(_x,W,_y,H);
	_s = new sf::CircleShape(10.0f);
}


Player::~Player() {
}

void Player::update(float dt) {
	float acc = 200000;
	float accX = 0;
	float accY = 0;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		accX+=acc;
	}


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		accX-=acc;
	}
	_dx *=0.9;
	_dx +=dt*accX;
	_x  +=dt*_dx;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		accY+=acc;
	}


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		accY-=acc;
	}
	_dy *=0.9;
	_dy +=dt*accY;
	_y  +=dt*_dy;
}

sf::Shape* Player::draw() {

	_s->setPosition(_x,_y);
	_s->setFillColor(sf::Color::White);
	return _s;
}

bool Player::isAlive() {
	return true;
}

float Player::getX() {
	return _x;
}


float Player::getY() {
	return _y;
}

