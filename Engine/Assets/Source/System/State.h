#pragma once

#include<SFML\Graphics.hpp>
#include"Window.h"

namespace summit {
	class State {
	protected:
		bool isPaused;
		std::string name;

	public:
		State(){}

		virtual void init() = 0;
		virtual void update(sf::Event &event) = 0;
		virtual void draw(Window *window) = 0;

		virtual void pause() = 0;
		virtual void resume() = 0;
		virtual void deinit() = 0;

		virtual std::string getName() = 0;
	};
}