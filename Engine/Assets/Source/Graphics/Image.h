#pragma once

#include<string>
#include<SFML\Graphics.hpp>
#include<iostream>
#include"..\System\Window.h"


namespace summit {
	class Image {
		sf::Texture texture;
		sf::Vector2f pos;
		sf::Sprite sprite;
	public:
		Image();
		Image(std::string filePath, sf::Vector2f pos);

		void init(std::string filePath, sf::Vector2f pos);
		void init(std::string filePath, sf::Vector2f pos, sf::IntRect crop);

		void resize(float factorX, float factorY);

		sf::Sprite *getSprite();

		void setPosition(sf::Vector2f pos);
		void draw(summit::Window *window);
	};
}