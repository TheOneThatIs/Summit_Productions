#define WIDTH 1280
#define HEIGHT 720
#define TITLE "v0.7a"
#include "TestGame.h"

#include<SFML\Graphics.hpp>

#include<Engine\Assets\Source\System\Window.h>
#include<Engine\Assets\Source\UI\Button.h>
#include<Engine\Assets\Source\Math\Vector.h>

#include<iostream>
#include<fstream>
#include<string>
#include<Engine\Assets\Source\Graphics\TextureCache.h>


TestGame::TestGame() :
	renderLayer(&window),
	cam(sf::FloatRect(0, 0, WIDTH, HEIGHT))
	{

	// WINDOW
		window.create(TITLE, WIDTH, HEIGHT);
		window.setKeyRepeatEnabled(true);
		window.setCam(cam);
		bindWindow(window);


	// TEST TEXT
		//testText.init("Hello world!", "Resources/Fonts/Arial/Arial.ttf", 50, sf::Color::White, 200.0f, 200.0f);
		//testText.setOrigin(sp::Text::MIDDLE);


	// TEST SAVE
		//playersave.associatefile("resources/saves/testfile.sav");
		//playersave.registerfloat("testgame::playerpos.x", &playerpos.x);
		//playersave.registerfloat("testgame::playerpos.y", &playerpos.y);
		//playersave.registerbool("testgame::isplayerrunning", &isplayerrunning);


	// BUTTON
		//button = new sp::Button;
		//button->init("resources/textures/button.png", sf::IntRect(0, 0, 200, 50), sp::Point(100, 0), &window);
	

	testVectors();

	//map.bindTileBatch(&tileBatch);
	//map.resize(100, 100);
	//map.setTileSize(25, 25);
	//map.load("Resources/Maps/Test World 1.csv");

	//anim.init("D:/Documents/Blender/Blends/My Blends/Lost Legacy/Renders/Loading",sf::IntRect(0, 0, 100, 100), 30);


	initTextures();
}

void TestGame::initTextures() {
	texture1.init(sp::TextureCache::getTexture("Resources/Textures/Test Sprite 1.png"));
	texture1.setUVs(0, 0, 1107, 833);

	texture2.init(sp::TextureCache::getTexture("Resources/Textures/Test Sprite 1.png"));
	texture1.setUVs(0, 0, 500, 833);

	texture3.init(sp::TextureCache::getTexture("Resources/Textures/Test Sprite 2.png"));
	texture1.setUVs(0, 0, 1333, 975);

	texture4.init(sp::TextureCache::getTexture("Resources/Textures/Test Sprite 2.png"));
	texture1.setUVs(0, 0, 500, 300);

	texture5.init(sp::TextureCache::getTexture("Resources/Textures/Test Sprite 2.png"));
	texture1.setUVs(200, 100, 1000, 775);

	texture6.init(sp::TextureCache::getTexture("Resources/Textures/Test Sprite 3.png"));
	texture1.setUVs(0, 0, 1093, 807);

	renderLayer.addImage(&texture1);
	renderLayer.addImage(&texture2);
	renderLayer.addImage(&texture3);
	renderLayer.addImage(&texture4);
	renderLayer.addImage(&texture5);
	renderLayer.addImage(&texture6);
	sp::Renderer::addLayer(&renderLayer);
}

void TestGame::testVectors() {
	sp::Vector v1(1.0f, 4.0f), v2(2.0f, 0.0f);

	sp::Vector v3 = v1 + v2;
	std::cout << "v1(1, 4) + v2(2, 0) = " << "v3" << &v3 << std::endl;

	v3 = v1 + 2;
	std::cout << "v1(1, 4) + 2 = " << "v3" << &v3 << std::endl;

	v3 = v1 - v2;
	std::cout << "v1(1, 4) - v2(2, 0) = " << "v3" << &v3 << std::endl;

	v3 = v1 - 2;
	std::cout << "v1(1, 4) - 2 = " << "v3" << &v3 << std::endl;

	v3 = v1 * v2;
	std::cout << "v1(1, 4) * v2(2, 0) = " << "v3" << &v3 << std::endl;

	v3 = v1 * 2;
	std::cout << "v1(1, 4) * 2 = " << "v3" << &v3 << std::endl;

	v1.setOrigin(2.f, 3.f);
	v1.normalize();
	std::cout << "v1(3, 2).normalize() = " << &v1 << std::endl;
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
				//if (button->update(mousePos))
					//std::cout << "Pressed the button!" << std::endl;
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Escape:
						deleteTextures();
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

	//animateText();
	//map.update();
}
void TestGame::deleteTextures() {
	texture1.~Image();
	texture2.~Image();
	texture3.~Image();
	texture4.~Image();
	texture5.~Image();
	texture6.~Image();
	sp::TextureCache::freeOrphans();
	renderer.removeLayer();
}

void TestGame::draw() {

	renderer.render();

	/*window.clear(sf::Color(0, 0, 0, 0));

	window.setCam(cam);
	testText.drawText(&window);
	button->draw();
	map.draw(&window);

	window.display();*/
}

void TestGame::moveCam() {
	//cam.move(player->getPos());
}

/*
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
*/