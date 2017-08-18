#define WIDTH 1280
#define HEIGHT 720
#define TITLE "Summit Productions Template"
#include "TestGame.h"
#include<iostream>

#include<Engine\Assets\Source\System\Window.h>
#include<fstream>
#include<string>




TestGame::TestGame() : playerSpeed(3), textRotation(0){
	// WINDOW
	windowPtr = &window;
	window.create(TITLE, WIDTH, HEIGHT);
	window.setKeyRepeatEnabled(false);

	// PLAYER
	img_player.init("Resources/Textures/Player.png", sf::Vector2f(0, 0));
	img_player.resize(.25f, .25);

	// TEST TEXT
	testText.init("Hello world!", "Resources/Fonts/Arial/Arial.ttf", 50, sf::Color::White, 200.0f, 200.0f);
	testText.setOrigin(summit::Text::MIDDLE);
}

void TestGame::start() {
	sf::Event event;
	gameCore.init(windowPtr);

	while (window.isOpen()) {
		gameCore.loopStart();
		gameCore.calculateFPS();
		
		while (gameCore.getAccumulator() > TARGET_FRAME_TIME) {
			gameCore.updateAsNeeded();
			this->update(event);
		}

		draw();
	}
}

void TestGame::update(sf::Event &event) {
	while (window.pollEvents(&event)) {
		switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseMoved:
				gameCore.updateCursorPos(event);
				mousePos = gameCore.getMousePos();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::A:
						movingLeft = true;
						break;
					case sf::Keyboard::S:
						movingDown = true;
						break;
					case sf::Keyboard::D:
						movingRight = true;
						break;
					case sf::Keyboard::W:
						movingUp = true;
						break;
					case sf::Keyboard::LShift:
						isPlayerRunning = !isPlayerRunning;
						break;
					case sf::Keyboard::Escape:
						fileManager.emptyFile("Resources/Saves/TestFile.sav");
						fileManager.write("Resources/Saves/TestFile.sav", "(TestGame:playerPos.x)" + to_string(playerPos.x) + "\n");
						fileManager.write("Resources/Saves/TestFile.sav", "(TestGame:playerPos.y)" + to_string(playerPos.y) + "\n");
						window.close();
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code) {
					case sf::Keyboard::A:
						movingLeft = false;
						break;
					case sf::Keyboard::S:
						movingDown = false;
						break;
					case sf::Keyboard::D:
						movingRight = false;
						break;
					case sf::Keyboard::W:
						movingUp = false;
						break;
					case sf::Keyboard::F11:
						window.toggleFullscreen();
					}
				break;
		}
	}
	updatePlayer();
	animateText();
}

void TestGame::updatePlayer() {
	if (!isPlayerRunning)
		playerSpeed = 3;
	else playerSpeed = 9;

	if (movingLeft)
		playerPos.x -= playerSpeed;
	if (movingDown)
		playerPos.y += playerSpeed;
	if (movingRight)
		playerPos.x += playerSpeed;
	if (movingUp)
		playerPos.y -= playerSpeed;

	
		img_player.setPosition(playerPos);
}

void TestGame::draw() {
	window.clear(sf::Color(0, 0, 0, 0));

	img_player.draw(windowPtr);
	testText.drawText(windowPtr);

	window.display();
}

void TestGame::animateText() {
	if(textRotation < 360)
		textRotation++;
	else textRotation = 0;

	testText.setRotation(textRotation);
}