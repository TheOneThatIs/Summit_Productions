#include"TextManager.h"


namespace summit {
	TextManager::TextManager(){}


	void TextManager::createText(std::string str, std::string fontName, int size, sf::Color color, sf::Vector2f pos) {  // LIMITATION: Can only have one font at a time
		if (!font.loadFromFile("Resources/Fonts/" + fontName + "/" + fontName + ".ttf"))
			std::cout << "Failed to load font with name \"" << fontName << "\"" << std::endl;

		text.setFont(font);
		text.setString(str);
		text.setCharacterSize(size);
		text.setColor(color);
		text.setPosition(pos);

		textStack.push_back(text);
	}

	void TextManager::createText(std::string str, int size, sf::Color color, int x, int y) {
		text.setString(str);
		text.setCharacterSize(size);
		text.setColor(color);
		text.setPosition(x, y);

		textStack.push_back(text);
	}			

	void TextManager::drawTexts(sf::RenderWindow &window) {
		for (int i = 0; i < textStack.size(); i++)
			if (textStack.size() > 0) 
				window.draw(textStack[i]);
	}
}