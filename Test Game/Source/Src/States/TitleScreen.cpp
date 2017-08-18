#include "States\TitleScreen.h"

#include<iostream>
#include<Engine\Assets\Source\System\StateManager.h>

extern sf::Vector2f mousePos;


TitleScreen::TitleScreen(std::string stateName) {
	name = stateName;

	//testButton.init("Resources/Textures/Button.png", 300.f, 20.f, sf::IntRect(0, 0, 199, 48), sf::IntRect(200, 0, 199, 48), sf::IntRect(0, 52, 199, 48));

	image.init("Resources/Textures/Background.png", sf::Vector2f(0, 0));
}

void TitleScreen::update(sf::Event &event) {
	if (!isPaused) {

		//if (testButton.update(event, mousePos))
			//buttonAction();

	}
}

void TitleScreen::draw(summit::Window *window) {
	image.draw(window);

	//testButton.draw(window);
}

void TitleScreen::pause() {
	isPaused = true;
}
void TitleScreen::resume() {
	isPaused = false;
}

std::string TitleScreen::getName() {
	return name;
}

void TitleScreen::buttonAction() {
	std::cout << "Entering game" << std::endl;
	//stateManager.deleteState();
	//stateManager.addState(&game);
}