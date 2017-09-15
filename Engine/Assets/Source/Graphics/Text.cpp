#include"Text.h"

namespace sp {
	Text::Text(){}
	Text::Text(string text, string fontName) {
	
	}

	void Text::init(string str, string fontPath, int size, sf::Color color, float x, float y) {
		this->font.loadFromFile(fontPath);

		text.setString(str);
		text.setFont(font);
		text.setCharacterSize(size);
		text.setColor(color);
		text.setPosition(x, y);
	}
	void Text::drawText(Window *window) {
		window->draw(text);
	}

	void Text::setFont(string fontPath) {
		if (!font.loadFromFile(fontPath)) {
			std::cout << "Cannot load font: \"" << fontPath << "\"" << std::endl;
		}
	}
	void Text::setSize(int size) {
		this->size = size;
	}
	void Text::setText(string text) {
		this->text.setString(text);
	}
	void Text::setPosition(float x, float y) {
		text.setPosition(sf::Vector2f(x, y));
	}
	void Text::setColor(sf::Color color) {
		text.setColor(color);
	}
	void Text::setRotation(float angle) {
		text.setRotation(angle);
	}
	void Text::setOrigin(Origin origin) {
		if(origin == MIDDLE)
			text.setOrigin(sf::Vector2f(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2));
		if (origin == RIGHT)
			text.setOrigin(sf::Vector2f(text.getLocalBounds().width, text.getLocalBounds().height / 2));
		if (origin == LEFT)
			text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2, text.getLocalBounds().height / 2));
	}
}