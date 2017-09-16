#include "GameCore.h"

#include<iostream>
#include<string>
#include<algorithm>


namespace sp {

	GameCore::GameCore() {
		mousePos = { 0, 0 };
		updateQueue = 0;
	}
	GameCore::~GameCore() {}



	void GameCore::init(Window *window, int targetFPS) {
		initStates();
		bindWindow(*window);
		targetFrameTime = (MS_PER_SEC / targetFPS);
	}


	void GameCore::initStates() {

	}

	void GameCore::deinit() {
		window->close();
	}

	void GameCore::bindWindow(Window &window) {
		this->window = &window;
	}

	void GameCore::timeStep() {
		//add last frame's time to accumulator
		accumulator += timer.getElapsedTime().asMilliseconds();

		//add last frame's time to time; reset timer to time upcoming frame
		time += timer.restart().asSeconds();

		//count fps and ups
		if (time >= 1.0f) { // 1 second passed
			//update fps with frame counter; reset frame counter
			fps = (float)frameCount / time;
			frameCount = 0;

			//update ups with update counter; reset update counter
			ups = (float)updateCount / time;
			updateCount = 0;

			//reset time
			time = 0.0;

			std::cout << "fps: " << fps << std::endl;
			std::cout << "ups: " << ups << std::endl;
		}

		updateQueue = 0;
		while (accumulator >= targetFrameTime) {
			updateCount++;

			accumulator -= targetFrameTime;

			updateQueue++;
		}
		//increment frame counter
		frameCount++;
	}
	
	void GameCore::updateCursorPos(sf::Event &event) {
		mousePos.x = (float)event.mouseMove.x;
		mousePos.y = (float)event.mouseMove.y;
	}
	sp::Point GameCore::getMousePos() {
		return mousePos;
	}

	int GameCore::getUpdateQueue() {
		return updateQueue;
	}
}