#pragma once
#include"System\Window.h"
#include"Math\Point.h"


namespace sp {
	class GameCore {
		Window *window;
		sp::Point mousePos;

		// TIME-STEP
		const float MS_PER_SEC = 1000;
		float targetFrameTime;
		int frameCount, updateCount;
		int updateQueue;
		sf::Clock timer;
		float accumulator;
		float time;
		float fps, ups;

	public:
		GameCore();
		~GameCore();

		void init(Window *window, int targetFPS);
		void initStates();
		void deinit();

		void bindWindow(Window &window);

		void updateCursorPos(sf::Event &event);
		sp::Point getMousePos();

		int getUpdateQueue();

		void timeStep();
	};
}