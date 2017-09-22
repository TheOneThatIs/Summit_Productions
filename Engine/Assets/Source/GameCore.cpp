#include "GameCore.h"

#include<iostream>
#include<string>
#include<algorithm>


namespace sp {

	GameCore::GameCore() {
		mousePos = { 0, 0 };
	}
	GameCore::~GameCore() {
		coreWindow->close();
	}



	void GameCore::gameLoop(sf::Event &event, int targetFPS){
		float targetFrameTime = 0;
		int frameCount = 0, updateCount = 0;
		sf::Clock timer;
		float accumulator = 0;
		float time = 0;


		targetFrameTime = (1.0f / targetFPS);

		while (coreWindow->isOpen()) {

			//add last frame's time to accumulator
			accumulator += timer.getElapsedTime().asSeconds();

			//add last frame's time to time; reset timer to time upcoming frame
			time += timer.restart().asSeconds();

			//count fps and ups
			if (time >= 1.0f) { // 1 second passed
								//update fps with frame counter; reset frame counter
				fps = (float)frameCount / time;
				frameCount = 0;

				//update ups with update counter; reset update counter
				ups = (float)updateCount;
				updateCount = 0;

				std::cout << "fps: " << fps << std::endl;
				std::cout << "ups: " << ups << std::endl;

				//reset time
				time = 0.0;
			}

			while (accumulator >= targetFrameTime) { // While we're behind on updates
				updateCount++;

				accumulator -= targetFrameTime;

				update(event);
			}
			//increment frame counter
			frameCount++;

			draw();
		}
	}

	void GameCore::bindWindow(Window &window) {
		this->coreWindow = &window;
	}
	
	void GameCore::updateCursorPos(sf::Event &event) {
		mousePos.x = (float)event.mouseMove.x;
		mousePos.y = (float)event.mouseMove.y;
	}

	Point GameCore::getMousePos() {
		return mousePos;
	}

	float GameCore::getFPS() {
		return fps;
	}
	float GameCore::getUPS() {
		return ups;
	}
}