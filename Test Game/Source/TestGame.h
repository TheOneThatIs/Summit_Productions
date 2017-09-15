#pragma once
#include<Engine\Assets\Source\GameCore.h>
#include<Engine\Assets\Source\Graphics\Image.h>
#include<Engine\Assets\Source\Graphics\Text.h>
#include<Engine\Assets\Source\Util\Save.h>
#include<Engine\Assets\Source\UI\GUI.h>
#include<Engine\Assets\Source\UI\Button.h>
#include<Engine\Assets\Source\Math\Point.h>
#include<Engine\Assets\Source\Graphics\Camera.h>
#include<Engine\Assets\Source\World\Entities\Entity.h>
#include<Engine\Assets\Source\World\World.h>
#include<Engine\Assets\Source\World\Map.h>
#include"Entities\Player.h"
#include"Blocks\Dirt.h"
#include"Blocks\Stone.h"



class TestGame {
	const float	TARGET_FPS = 30; // ***BUG***   values higher than 31 break the game
	const float MS_PER_SEC = 1000;
	const float TARGET_FRAME_TIME = (MS_PER_SEC / TARGET_FPS);

	
	// WINDOW
	sp::Window window;
	sp::Window *windowPtr;
	sp::Camera cam;

	sp::GameCore gameCore;

	sp::Point mousePos;


	// TEST TEXT
	sp::Text testText;
	float textRotation;
	sf::Color textColor;
	float textTime;
	bool textTimeUp;

	// TEST FILE
	sp::Save playerSave;


	// BUTTON
	sp::GUI *button;


	// WORLD
	sp::World world;
	sp::Map testMap1;
	sp::Map testMap2;
	Player player;
	Player player2;
	Player player3;
	Dirt dirt;
	Stone stone;

public:
	TestGame();

	void start();

private:
	void testVectors();
	void update(sf::Event &event);
	void draw();

	void moveCam();
	void animateText();
};