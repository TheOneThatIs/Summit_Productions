#pragma once
#include<Engine\Assets\Source\GameCore.h>
#include<Engine\Assets\Source\Graphics\Image.h>
#include<Engine\Assets\Source\Graphics\Text.h>
#include<Engine\Assets\Source\Util\FileManager.h>


class TestGame {
	// 
	const float	TARGET_FPS = 30; // ***BUG***   values higher than 31 break the game
	const float MS_PER_SEC = 1000;
	const float TARGET_FRAME_TIME = (MS_PER_SEC / TARGET_FPS);
	
	// WINDOW
	summit::Window window;
	summit::Window *windowPtr;

	summit::GameCore gameCore;

	sf::Vector2f mousePos;


	// PLAYER
	summit::Image img_player;
	sf::Vector2f playerPos;
	float playerSpeed;
	bool movingRight, movingLeft, movingUp, movingDown;
	bool isPlayerRunning;

	// TEST TEXT
	summit::Text testText;
	float textRotation;

	// TEST FILE
	summit::FileManager fileManager;


public:
	TestGame();

	void start();

private:
	void update(sf::Event &event);
	void updatePlayer();
	void draw();

	void animateText();
};