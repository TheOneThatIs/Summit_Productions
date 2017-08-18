#pragma once

#include "UI.h"
#include"..\Graphics\Image.h"

#include<string>
#include<SFML\Graphics.hpp>
#include<functional>

namespace summit {
	class Button : public UI {
		enum ButtonState{
			NORMAL, HOVER, CLICKED
		}state;

		summit::Image normal, hover, clicked;
		summit::Image *currentStateImage;
		float width, height, left, top;
		bool buttonDown;

	public:
		Button();

		void init(std::string filePath, sf::Vector2f pos, sf::IntRect intRect);
		void init(std::string filePath, sf::Vector2f pos, sf::IntRect intRectNormal, sf::IntRect intRectHover, sf::IntRect intRectClicked);

		bool update(sf::Event &event, sf::Vector2f mousePos);

		void draw(sf::RenderWindow *window);

	private:
		bool handleEvents(sf::Event &event, sf::Vector2f mousePos);
	};
}