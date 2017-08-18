#include"Test Game\Source\Inc\States\Game.h"



Game::Game(std::string stateName) {
	name = stateName;
}

void Game::update(sf::Event &event) {}
void Game::draw(summit::Window *window) {
	
}

void Game::pause() {}
void Game::resume() {}

std::string Game::getName() {
	return name;
}