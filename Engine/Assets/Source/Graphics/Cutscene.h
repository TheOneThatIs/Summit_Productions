#pragma once

#include<vector>
#include"Image.h"
#include"..\System\Window.h"


namespace summit {

class Cutscene {
	int numFrames;
	int currentFrame;
	bool paused;
	std::string animPath;
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Texture> textures;

public:
	Cutscene();

	void init(int numFrames, std::string animPath);
	
	void pause();
	void play();
	void restart();

	void update(float deltaTime);
	void draw(summit::Window *window);

	bool isPaused();

private:
	void loadAnimation();
};

}