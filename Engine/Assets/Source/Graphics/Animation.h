#pragma once

#include<iostream>
#include<string>
#include<SFML\Graphics.hpp>
#include"Image.h"


namespace sp {
	class Animation {
		sf::Sprite spritesheet;

		sf::IntRect srcRect;
		int interval;
		int currentTime, pollFrequency;
		int numFrames;
		bool isLooped, isAnimationFinished;
	
	public:
		Animation() {}

		Animation(std::string filepath, sf::IntRect srcRect, int pollFrequency, int numFrames) : currentTime(0), isLooped(false), isAnimationFinished(false) {
			//spritesheet = spriteManager.createSprite(filepath);

			this->pollFrequency = pollFrequency;
			interval = srcRect.width;
			this->srcRect = srcRect;
			this->numFrames = numFrames;
		}

		void init(std::string filepath, sf::IntRect srcRect, int pollFrequency, int numFrames) {
			currentTime = 0;
			isLooped = true;
			isAnimationFinished = false;

			//spritesheet = sp::Image::createSprite(filepath);

			this->pollFrequency = pollFrequency;
			interval = srcRect.width;
			this->srcRect = srcRect;
			this->numFrames = numFrames;
		}

		void update() {
			currentTime++;
			if (currentTime == pollFrequency) {
				if (srcRect.left != srcRect.width*numFrames && !isAnimationFinished) //If not end of animation and animation is not finished
					srcRect.left += srcRect.width;//Next frame

				if (srcRect.left == srcRect.width*(numFrames)) {//If reached the end of animation
					if (isLooped)
						srcRect.left = 0;//Restart animation
					else isAnimationFinished = true;
				}
			}
			if (currentTime >= pollFrequency)
				currentTime = 0;//Reset timer
		}

		void draw(sf::RenderWindow &window, sf::Vector2f pos) {
			spritesheet.setTextureRect(srcRect);
			window.draw(spritesheet);
		}

		void setLoop(bool isLooped) {
			this->isLooped = isLooped;
		}
	};
}