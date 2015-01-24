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
	bodyDef.position.Set(_x,_y );
	bodyDef.allowSleep = false;
	body = map->world->CreateBody(&bodyDef);
	b2PolygonShape *dynamicBox = new b2PolygonShape();

	dynamicBox->SetAsBox(W/2.f, H/2.f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.8f;
	body->CreateFixture(&fixtureDef);
	
	_s->setPosition(_x,_y);


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

/*	if(_box->x <=0) {
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
	}*/


	auto tab = _map->getTab();
	for(auto t : tab) {

		if(_box->AABB(t.second->box)){

		}
	}


	_dx *=0.85;
	_dx +=dt*accX;
	_box->x  +=dt*_dx;

	_dy *=0.85;
	_dy +=dt*accY;
	_box->y  +=dt*_dy;
	//	body->SetTransform(b2Vec2(body->GetPosition().x+dt*_dx,body->GetPosition().y+dt*_dy),body->GetAngle());
	b2Vec2 vel = body->GetLinearVelocity();
	vel.x = dt*_dx*10000;
	vel.y = dt*_dy*10000;
	body->SetLinearVelocity( vel );
//	std::cout <<body->GetPosition().x<< std::endl; 
}

sf::Shape* Player::draw() {
	_s->setFillColor(sf::Color::White);
	_s->setPosition(body->GetPosition().x,body->GetPosition().y);

	return _s;
}

bool Player::isAlive() {
	return true;
}

float Player::getX() {
	return body->GetPosition().x;
}


float Player::getY() {
	return body->GetPosition().y;
}

