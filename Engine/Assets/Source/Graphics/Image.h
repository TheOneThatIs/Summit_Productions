#pragma once

#include<string>
#include<SFML\Graphics.hpp>
#include<iostream>
#include"..\System\Window.h"
#include"..\Math\Point.h"


namespace sp {
	class Image {
		sf::Texture texture;
		sp::Point pos;
		sf::Sprite sprite;
	public:
		Image();
		Image(std::string filePath, sp::Point pos);

		void init(std::string filePath, sp::Point pos);
		void init(std::string filePath, sp::Point, sf::IntRect crop);

		void resize(float factorX, float factorY);

		sf::Sprite *getSprite();

		void setPosition(sp::Point pos);
		void draw(sp::Window *window);
	};
}