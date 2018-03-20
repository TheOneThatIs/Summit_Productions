#pragma once
#include<Engine\Assets\Source\GameCore.h>
#include<Engine\Assets\Source\Graphics\Text.h>
#include<Engine\Assets\Source\Graphics\Camera.h>
#include<Engine\Assets\Source\Util\Save.h>
#include<Engine\Assets\Source\UI\GUI.h>
#include<Engine\Assets\Source\Math\Point.h>

#include<Engine\Assets\Source\World\TileMap.h>

#include<Engine\Assets\Source\Graphics\Animation.h>

#include<Engine\Assets\Source\Graphics\Renderer.h>


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
	//sp::GUI *button;

	sp::TileMap map;

	sp::Animation anim;
	sp::Renderer renderer;

	sp::Image texture1;
	sp::Image texture2;
	sp::Image texture3;
	sp::Image texture4;
	sp::Image texture5;
	sp::Image texture6;

	sp::RenderLayer renderLayer;

public:
	TestGame();

private:
	void initTextures();

	void testVectors();
	void update(sf::Event &event) override;
	void draw() override;

	void deleteTextures();

	void moveCam();
	void animateText();
};