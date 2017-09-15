#pragma once

#include<SFML\Graphics.hpp>
#include"..\Graphics\Image.h"
#include"..\Math\Point.h"

namespace sp {
	class GUI {
	protected:
		sp::Window *windowPtr;
		Image image;
		sp::Point pos;
		sf::IntRect hitBox;

	public:
		GUI();
		GUI(sp::Window *window);

		void init(std::string filePath, sf::IntRect hitBox, sp::Point pos, sp::Window *window);

		void draw();

		void setPosition(sp::Point pos);
		sp::Point getPosition();

		void setTexture(Image image);
		void setTexture(std::string filePath);

		void setHitBox(sf::IntRect hitBox);
		bool update(sp::Point mousePos);

		void move(float x, float y);

	};

}