#include "Game.h"
#include<iostream>



Game::Game(): window("Template", 800, 500) {
	button = new sp::Button();
	sp::Point point(10, 100);
	button->init("Button.png", sf::IntRect(0, 0, 200, 50), point, &window);
	gameLoop();
}

void Game::gameLoop() {
	sf::Event event;

	while (window.isOpen()) {

		while (window.pollEvents(&event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		draw();
	}
}

void Game::draw() {
	window.clear(sf::Color(0, 0, 0, 0));

	button->draw();

	window.display();
}