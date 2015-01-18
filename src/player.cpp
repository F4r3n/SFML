#include "player.h"
#include "engineConst.h"
#include <iostream>

Player::Player(Map *map):Entity(map){
	_x = 100;
	_y = 100;
	_dx = 0;
	_dy = 0;
	_box = new Box(_x,W,_y,H);
	_s = new sf::RectangleShape(sf::Vector2f(W,H));
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		accY+=acc;
	}


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		accY-=acc;
	}

	if(_x >= EngineConst::WIDTH-_box->w) {
		_dx = 0;
		_x = EngineConst::WIDTH-_box->w;
	}
	if(_x <=0) {
		_dx = 0;
		_x = 0;
	}

	if(_y >= EngineConst::HEIGHT-_box->h) {
		_dy = 0;
		_y = EngineConst::HEIGHT-_box->h;
	}
	if(_y <=0) {
		_dy = 0;
		_y = 0;
	}
	

	_dx *=0.9;
	_dx +=dt*accX;
	_x  +=dt*_dx;

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

