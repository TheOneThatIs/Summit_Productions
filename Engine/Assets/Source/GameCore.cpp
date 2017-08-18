#define TARGET_FPS 30
#define MS_PER_SEC 1000
#define TARGET_FRAME_TIME (MS_PER_SEC / TARGET_FPS)

#include "GameCore.h"

#include<iostream>
#include<string>
#include<algorithm>


namespace summit {

	GameCore::GameCore() {
		mousePos = { 0, 0 };
	}
	GameCore::~GameCore() {}



	void GameCore::init(Window *window) {
		accumulator = 0;
		time = 0;
		frameCount = 0;
		updateCount = 0;
		fps = 0.0f;
		ups = 0.0f;

		initStates();
		bindWindow(*window);
	}


	void GameCore::initStates() {

	}

	void GameCore::deinit() {
		window->close();
	}

	void GameCore::bindWindow(Window &window) {
		this->window = &window;
	}

	void GameCore::loopStart() {
		//add last frame's time to accumulator
		accumulator += timer.getElapsedTime().asMilliseconds();

		//add last frame's time to time; reset timer to time upcoming frame
		time += timer.restart().asSeconds();

		//increment frame counter
		frameCount++;
	}

	void GameCore::calculateFPS() {
		//count fps and ups
		if (time >= 1.0f) { // 1 second passed
			//update fps with frame counter; reset frame counter
			fps = (float)(frameCount / time);
			frameCount = 0;

			//update ups with update counter; reset update counter
			ups = (float)(updateCount / time);
			updateCount = 0;

			//reset time
			time = 0.0;
		}
	}

	void GameCore::printFPS() {
		std::cout << "fps: " << fps << std::endl;
	}
	void GameCore::printUPS() {
		std::cout << "ups: " << ups << std::endl;
	}

	void GameCore::updateAsNeeded() {
		//update the game as many times as needed to keep a fixed update time
		while (accumulator >= TARGET_FRAME_TIME) {
			//increment update counter
			updateCount++;

			//sub frametime from accumulater
			accumulator -= TARGET_FRAME_TIME;
		}
	}
	
	void GameCore::updateCursorPos(sf::Event &event) {
		mousePos.x = (float)event.mouseMove.x;
		mousePos.y = (float)event.mouseMove.y;
	}
	sf::Vector2f GameCore::getMousePos() {
		return mousePos;
	}

	float GameCore::getAccumulator() {
		return accumulator;
	}
}