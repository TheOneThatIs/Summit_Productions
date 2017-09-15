#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<SFML\Graphics.hpp>

#include"..\System\Window.h"

#include<vector>

using namespace std;

namespace sp {

	class Text {
		int size, x, y;
		sf::Font font;
		sf::Text text;

	public:
		enum Origin {
			LEFT, RIGHT, MIDDLE
		};
		Text();
		Text(string text, string fontName);

		void init(string str, string fontPath, int size, sf::Color color, float x, float y);
		void drawText(Window *window);

		void setFont(string fontPath);
		void setSize(int size);
		void setText(string text);
		void setPosition(float x, float y);
		void setColor(sf::Color color);
		void setRotation(float angle);
		void setOrigin(Origin origin);
	};

}