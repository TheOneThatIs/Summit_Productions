#pragma once
#include"System\Window.h"
#include"Math\Point.h"


namespace sp {
	class GameCore {
		Window *window;
		sf::Clock timer;
		float accumulator;
		float time;
		int frameCount;
		int updateCount;
		float fps;
		float ups;
		sp::Point mousePos;

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
		sp::Point getMousePos();

		float getAccumulator();

		void calculateFPS();
		void loopStart();
	};
}