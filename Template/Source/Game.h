#pragma once
#include<Engine\Assets\Source\System\Window.h>
#include<Engine\Assets\Source\UI\GUI.h>
#include<Engine\Assets\Source\UI\Button.h>


class Game{
	sp::Window window;
	sp::GUI *button;

public:
	Game();

	void draw();
	void gameLoop();
};