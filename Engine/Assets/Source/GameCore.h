#pragma once
#include"System\Window.h"
#include"Math\Point.h"


namespace sp {
	class GameCore {
		Window *coreWindow;
		sp::Point mousePos;

		float fps, ups;

	public:
		GameCore();
		~GameCore();

		virtual void draw() = 0;
		virtual void update(sf::Event &event) = 0;

		virtual void gameLoop(sf::Event &event, int targetFPS);

		void bindWindow(Window &window);

		void updateCursorPos(sf::Event &event);
		Point getMousePos();

		float getFPS();
		float getUPS();
	};
}