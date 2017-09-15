#pragma once

#include "GUI.h"
#include"..\Graphics\Image.h"

#include<string>
#include<SFML\Graphics.hpp>



namespace sp {
	class Button : public GUI {
	public:
		enum ButtonState {
			NORMAL, HOVER, CLICKED
		}state;

		Button();
	};
}






/*namespace sp {
	class Button : public UI {
		enum ButtonState{
			NORMAL, HOVER, CLICKED
		}state;

		sp::Image normal, hover, clicked;
		sp::Image *currentStateImage;
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
}*/