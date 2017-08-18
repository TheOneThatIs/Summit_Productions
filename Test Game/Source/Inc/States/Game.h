#pragma once

#include<Engine\Assets\Source\System\State.h>
#include<Engine\Assets\Source\System\Window.h>



class Game : public summit::State {
public:
	Game() {}
	Game(std::string stateName);
	~Game() {}

	void init() override {}
	void update(sf::Event &event) override;
	void draw(summit::Window *window) override;

	void pause() override;
	void resume() override;

	void deinit() override {}

	std::string getName() override;
};