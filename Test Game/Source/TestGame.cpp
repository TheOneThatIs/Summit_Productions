#define WIDTH 1280
#define HEIGHT 720
#define TITLE "v0.5.1a"
#include "TestGame.h"

#include<SFML\Graphics.hpp>

#include<Engine\Assets\Source\System\Window.h>
#include<Engine\Assets\Source\UI\Button.h>
#include<Engine\Assets\Source\Math\Vector.h>

#include<iostream>
#include<fstream>
#include<string>


TestGame::TestGame() :
	testMap1(0, "Resources/Maps/Small World Test.csv"), testMap2(1, "Resources/Maps/Test World 1.csv"),
	player(Player(0)), player2(Player(1)), player3(Player(2)),
	cam(sf::FloatRect(0, 0, WIDTH, HEIGHT)),
	textRotation(0), textColor(0, 0, 0, 255), textTime(0){

	// WINDOW
		window.create(TITLE, WIDTH, HEIGHT);
		window.setKeyRepeatEnabled(true);
		window.setCam(cam);
		bindWindow(window);


	// TEST TEXT
		testText.init("Hello world!", "Resources/Fonts/Arial/Arial.ttf", 50, sf::Color::White, 200.0f, 200.0f);
		testText.setOrigin(sp::Text::MIDDLE);


	// TEST SAVE
		//playersave.associatefile("resources/saves/testfile.sav");
		//playersave.registerfloat("testgame::playerpos.x", &playerpos.x);
		//playersave.registerfloat("testgame::playerpos.y", &playerpos.y);
		//playersave.registerbool("testgame::isplayerrunning", &isplayerrunning);


	// BUTTON
		button = new sp::Button;
		button->init("resources/textures/button.png", sf::IntRect(0, 0, 200, 50), sp::Point(100, 0), &window);
	

	//testvectors();


	// WORLD
		registerEntities();
		registerTiles();
		registerMaps();
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
				updateCursorPos(event);
				mousePos = getMousePos();
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
		world.update(event);
	}

	animateText();
}

void TestGame::draw() {
	window.clear(sf::Color(255, 255, 255, 0));

	window.setCam(cam);
	//world.draw(&window);
	testText.drawText(&window);
	button->draw();

	window.display();
}

void TestGame::registerEntities(){
	world.registerEntity(&player);
	world.registerEntity(&player2);
	world.registerEntity(&player3);
}

void TestGame::registerTiles() {
	world.registerTile(new Dirt(0));
	world.registerTile(new Stone(1));
}

void TestGame::registerMaps() {
	world.registerTileMap(&testMap1);
	world.registerTileMap(&testMap2);
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