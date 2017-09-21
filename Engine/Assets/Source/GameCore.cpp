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
		targetFrameTime = (1.0f / targetFPS);
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
		accumulator += timer.getElapsedTime().asSeconds();

		//add last frame's time to time; reset timer to time upcoming frame
		time += timer.restart().asMilliseconds();

		//count fps and ups
		if (time >= 100.0f) { // 1 second passed
			//update fps with frame counter; reset frame counter
			fps = (float)frameCount / time;
			frameCount = 0;

			//update ups with update counter; reset update counter
			ups = (float)updateCount;
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

	Point GameCore::getMousePos() {
		return mousePos;
	}

	float GameCore::getFPS() {
		return fps;
	}
	float GameCore::getUPS() {
		return ups;
	}
	float GameCore::getDeltaTime() {
		//return deltaTime;
		return 0.0f;
	}

	int GameCore::getUpdateQueue() {
		return updateQueue;
	}
}