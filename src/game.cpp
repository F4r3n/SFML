#include <iostream>
#include "level.h"
#include "game.h"

Game::Game() {

}

Game::~Game() {

}

void Game::changeLevel() {
_level.setLevel(0);	
}

void Game::update(float dt) {
	_level.update(dt);
}

void Game::draw(sf::RenderWindow &window){
_level.draw(window);
}

