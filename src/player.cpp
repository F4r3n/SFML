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
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(_x/30.f,_y/30.f );
	body = map->world->CreateBody(&bodyDef);
	b2PolygonShape *dynamicBox = new b2PolygonShape();

	dynamicBox->SetAsBox(W, H);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);


}


Player::~Player() {
}

void Player::update(float dt) {
	std::cout << body->GetWorld()->GetGravity().y <<std::endl;
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

	_s->setPosition(_x,_y);
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

