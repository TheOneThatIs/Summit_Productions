#pragma once

#include<vector>
#include<iostream>
#include<SFML\Graphics.hpp>


namespace summit {

	class TextManager {
		std::vector<sf::Text> textStack;
		sf::Text text;
		sf::Font font;
	public:
		TextManager();

		void createText(std::string str, std::string fontName, int size, sf::Color color, sf::Vector2f pos);
		void createText(std::string str, int size, sf::Color color, int x, int y);

		void drawTexts(sf::RenderWindow &window);
	};

}