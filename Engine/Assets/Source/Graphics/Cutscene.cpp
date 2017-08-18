#include"Cutscene.h"
#include<sstream>



namespace summit {
	Cutscene::Cutscene() : numFrames(0), currentFrame(0), paused(true) {

	}


	void Cutscene::init(int numFrames, std::string animPath){
		this->numFrames = numFrames;
		this->animPath = animPath;
		loadAnimation();
	}

	void Cutscene::pause(){
		paused = true;
	}
	void Cutscene::play(){
		paused = false;
	}
	void Cutscene::restart(){
		currentFrame = 0;
	}

	void Cutscene::update(float deltaTime){
		if (!paused) {
			
			if (currentFrame < numFrames - 1) {
				currentFrame++;
			}

		}
	}

	void Cutscene::draw(summit::Window *window){
		window->draw( sprites[currentFrame] );
	}

	bool Cutscene::isPaused() {
		return paused;
	}

	void Cutscene::loadAnimation(){ // ***RUNS VERY SLOWLY***
		textures.reserve(numFrames);
		std::string fileName = "-1";
		int fileAsInt;

		for (int i = 0; i < numFrames; i++) {
			fileAsInt = std::stoi(fileName);
			fileAsInt += 1;
			fileName = std::to_string(fileAsInt);

			textures.push_back(sf::Texture());
			textures[i].loadFromFile(animPath + fileName + ".png");

			sprites.push_back(sf::Sprite());
			sprites[i].setTexture( textures[i] );
		}
	}
}