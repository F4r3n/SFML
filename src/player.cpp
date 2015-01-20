#include "player.h"
#include "engineConst.h"
#include <iostream>

Player::Player(Map *map):Entity(map){
	_x = 0;
	_y = 0;
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

	if(_box->x >= EngineConst::WIDTH-_box->w) {
		_dx = 0;
		_box->x = EngineConst::WIDTH-_box->w;
	}

	if(_box->x <=0) {
		_dx = 0;
		_box->x = 0;
	}

	if(_box->y >= EngineConst::HEIGHT-_box->h) {
		_dy = 0;
		_box->y = EngineConst::HEIGHT-_box->h;
	}
	if(_box->y <=0) {
		_dy = 0;
		_box->y = 0;
	}


	auto tab = _map->getTab();
	for(auto t : tab) {

		if(_box->AABB(t.second->box)){
			int dir = _box->direction(t.second->box);
		//	std::cout << dir <<std::endl;
			if(dir ==0) {
				_dx = 0;
				accX=0;
				_box->x = t.second->box->x-W;
				
			}
			else if(dir==1) {
				accX=0;
				_dx = 0;
				_box->x = t.second->box->x+t.second->box->w;
			}
			else if(dir ==2) {
				accY=0;
				_dy = 0;
				_box->y = t.second->box->y-H;
				
			}
			else if(dir==3) {
				accY=0;
				_dy = 0;
				_box->y = t.second->box->y+t.second->box->h;
			}
			else {
				_dx = 0;
				_dy = 0;
			}

		}
	}


	_dx *=0.9;
	_dx +=dt*accX;
	_box->x  +=dt*_dx;

	_dy *=0.9;
	_dy +=dt*accY;
	_box->y  +=dt*_dy;
}

sf::Shape* Player::draw() {

	_s->setPosition(_box->x,_box->y);
	_s->setFillColor(sf::Color::White);
	return _s;
}

bool Player::isAlive() {
	return true;
}

float Player::getX() {
	return _box->x;
}


float Player::getY() {
	return _box->y;
}

