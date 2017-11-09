#pragma once
#include<Engine\Assets\Source\GameCore.h>
#include<Engine\Assets\Source\Graphics\Text.h>
#include<Engine\Assets\Source\Graphics\Camera.h>
#include<Engine\Assets\Source\Util\Save.h>
#include<Engine\Assets\Source\UI\GUI.h>
#include<Engine\Assets\Source\Math\Point.h>

#include<Engine\Assets\Source\World\TileMap.h>

#include"Tiles\TileBatch.h"



class TestGame : public sp::GameCore {
	// WINDOW
	sp::Window window;
	sp::Camera cam;

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

	sp::TileMap map;
	TileBatch tileBatch;

public:
	TestGame();

private:
	void testVectors();
	void update(sf::Event &event) override;
	void draw() override;

	void moveCam();
	void animateText();
};