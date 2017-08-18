#pragma once

#include<SFML\Graphics.hpp>

#include<Engine\Assets\Source\System\State.h>
#include<Engine\Assets\Source\Graphics\Animation.h>
#include<Engine\Assets\Source\Graphics\Image.h>
#include<Engine\Assets\Source\System\Window.h>

#include"States\Game.h"


class TitleScreen : public summit::State {
	sf::Font arial;
	sf::Font segoeScript;

	summit::Image image;

public:
	TitleScreen() {}
	TitleScreen(std::string stateName);
	~TitleScreen() {}

	void init() override {}
	void update(sf::Event &event) override;
	void draw(summit::Window *window) override;

	void pause() override;
	void resume() override;

	void deinit() override {}

	std::string getName() override;

private:
	void buttonAction();
};