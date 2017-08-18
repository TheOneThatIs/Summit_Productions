#pragma once
#include<SFML\Graphics.hpp>
#include"System\Window.h"



namespace summit {
	class GameCore {
		Window *window;
		sf::Clock timer;
		float accumulator;
		float time;
		int frameCount;
		int updateCount;
		float fps;
		float ups;
		sf::Vector2f mousePos;

	public:
		GameCore();
		~GameCore();

		void init(Window *window);
		void initStates();
		void deinit();

		void bindWindow(Window &window);

		void updateAsNeeded();

		void printFPS();
		void printUPS();

		void updateCursorPos(sf::Event &event);
		sf::Vector2f getMousePos();

		float getAccumulator();

		void calculateFPS();
		void loopStart();
	};
}