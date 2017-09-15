#define WIDTH 1280
#define HEIGHT 720
#define TITLE "v0.4a"
#include "TestGame.h"
#include<iostream>

#include<Engine\Assets\Source\System\Window.h>
#include<fstream>
#include<string>
#include<SFML\Graphics.hpp>
#include<Engine\Assets\Source\Math\Vector.h>


TestGame::TestGame() :
	player(Player(1)),
	player2(Player(2)),
	player3(Player(3)),
	cam(sf::FloatRect(0, 0, WIDTH, HEIGHT)),
	textRotation(0),
	textColor(0, 0, 0, 255),
	textTime(0),
	textTimeUp(true){


	// WINDOW
	windowPtr = &window;
	window.create(TITLE, WIDTH, HEIGHT);
	window.setKeyRepeatEnabled(true);
	window.setCam(cam);


	// TEST TEXT
	testText.init("Hello world!", "Resources/Fonts/Arial/Arial.ttf", 50, sf::Color::White, 200.0f, 200.0f);
	testText.setOrigin(sp::Text::MIDDLE);


	// TEST SAVE
	//playerSave.associateFile("Resources/Saves/TestFile.sav");
	//playerSave.registerFloat("TestGame::playerPos.x", &playerPos.x);
	//playerSave.registerFloat("TestGame::playerPos.y", &playerPos.y);
	//playerSave.registerBool("TestGame::isPlayerRunning", &isPlayerRunning);


	// BUTTON
	button = new sp::Button;
	button->init("Resources/Textures/Button.png", sf::IntRect(0, 0, 200, 50), sp::Point(100, 0), windowPtr);
	

	//testVectors();


	// WORLD
	world.registerBlock(4, &stone);
	world.registerBlock(0, &dirt);
	testMap1.loadMap("Resources/Maps/Test World 1.csv", world.getBlockRegistry());
	world.setMap(&testMap1);
	world.spawn(&player, 0, 0);
	world.spawn(&player2, 100, 100);
	world.spawn(&player3, 200, 300);
}

void TestGame::start() {
	sf::Event event;
	gameCore.init(windowPtr);

	playerSave.load();

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

void TestGame::testVectors() {
	sp::Vector v1(1.0f, 4.0f), v2(2.0f, 0.0f);

	sp::Vector v3 = v1 + v2;
	std::cout << "v1(1, 4) + v2(2, 0) = " << "v3(" << v3.getOrigin().x << ", " << v3.getOrigin().y << ")" << std::endl;

	v3 = v1 + 2;
	std::cout << "v1(1, 4) + 2 = " << "v3(" << v3.getOrigin().x << ", " << v3.getOrigin().y << ")" << std::endl;

	v3 = v1 - v2;
	std::cout << "v1(1, 4) - v2(2, 0) = " << "v3(" << v3.getOrigin().x << ", " << v3.getOrigin().y << ")" << std::endl;

	v3 = v1 - 2;
	std::cout << "v1(1, 4) - 2 = " << "v3(" << v3.getOrigin().x << ", " << v3.getOrigin().y << ")" << std::endl;

	v3 = v1 * v2;
	std::cout << "v1(1, 4) * v2(2, 0) = " << "v3(" << v3.getOrigin().x << ", " << v3.getOrigin().y << ")" << std::endl;

	v3 = v1 * 2;
	std::cout << "v1(1, 4) * 2 = " << "v3(" << v3.getOrigin().x << ", " << v3.getOrigin().y << ")" << std::endl;

	v1.setOrigin(2.f, 3.f);
	v1.normalize();
	std::cout << "v1(3, 2).normalize() = " << "(" << v1.getOrigin().x << ", " << v1.getOrigin().y << ")" << std::endl;
	std::cout << "v1.getMagnitude() = " << v1.getMagnitude() << std::endl;
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
			case sf::Event::MouseButtonPressed:
				if (button->update(mousePos))
					std::cout << "Pressed the button!" << std::endl;
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Escape:
						playerSave.save();
						break;
					case sf::Keyboard::Tilde:
						playerSave.load();
						break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code) {
					case sf::Keyboard::F11:
						window.toggleFullscreen();
					}
				break;
		}
	}
	world.update();

	animateText();
}

void TestGame::draw() {
	window.clear(sf::Color(0, 0, 0, 0));

	window.setCam(cam);
	world.draw(&window);
	testText.drawText(&window);
	button->draw();

	window.display();
}

void TestGame::moveCam() {
	//cam.move(player->getPos());
}

void TestGame::animateText() {
	if (textRotation < 360)
		textRotation++;
	else textRotation = 0;

	testText.setRotation(textRotation);

	// cos(x) returns a value between -1 and 1. To convert it into the range 0 to 1 you do:
	// (cos(x) + 1) * 0.5
	textColor.r = std::cos((textTime+1)*.5f) * 255;
	textColor.g = std::sin((textTime+1)*.5f) * 255;
	textColor.b = std::cos((textTime+1)*.5f) * 255;

	testText.setColor(textColor);
	testText.setPosition(std::abs(std::cos((textTime + 1)*.5f) * 255), std::abs(std::cos((textTime + 1)*.5f) * 255));
	
	textTime -= .05f;
}