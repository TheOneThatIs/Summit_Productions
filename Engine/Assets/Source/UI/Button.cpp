#include"Button.h"

#include<iostream>

extern sf::Vector2f mousePos;

namespace summit {
	Button::Button() {
		currentStateImage = &normal;
		buttonDown = false;
	}

	void Button::init(std::string filePath, sf::Vector2f pos, sf::IntRect intRect) {
		texture.loadFromFile(filePath);
		setPosition(pos);
		this->pos = pos;
		//setTextureRect(intRect);
		width = intRect.width;
		height = intRect.height;
		left = intRect.left;
		top = intRect.top;
	}

	void Button::init(std::string filePath, sf::Vector2f pos, sf::IntRect intRectNormal, sf::IntRect intRectHover, sf::IntRect intRectClicked) {
		
		
		
		//normal.getTexture()->loadFromFile(filePath, intRectNormal);
		//hover.getTexture()->loadFromFile(filePath, intRectHover);
		//clicked.getTexture()->loadFromFile(filePath, intRectClicked);

		//normal.getSprite()->setTexture(*normal.getTexture());
		//hover.getSprite()->setTexture(*hover.getTexture());
		//clicked.getSprite()->setTexture(*clicked.getTexture());
		
		normal.setPosition(pos);
		hover.setPosition(pos);
		clicked.setPosition(pos);

		this->pos = pos;

		width = intRectNormal.width;
		height = intRectNormal.height;
		left = intRectNormal.left;
		top = intRectNormal.top;
	}

	bool Button::update(sf::Event &event, sf::Vector2f mousePos) {
		if (handleEvents(event, mousePos))
			return true;
		else return false;
	}

	bool Button::handleEvents(sf::Event &event, sf::Vector2f mousePos) {
		if (mousePos.x >= x && mousePos.x < x + width && mousePos.y >= y && mousePos.y <= y + height) { // If over button
			if (event.type == sf::Event::MouseButtonPressed || buttonDown) { // If button is held
				state = CLICKED;
				currentStateImage = &clicked;
				buttonDown = true;
			}
			if (event.type == sf::Event::MouseButtonReleased) { // If button is clicked
				state = HOVER;
				currentStateImage = &hover;
				buttonDown = false;
				return true;
			} else if(!buttonDown){
				state = HOVER;
				currentStateImage = &hover;
			}
		} else { // Not hovering over button
			if (event.type == sf::Event::MouseButtonReleased)
				buttonDown = false;
			state = NORMAL;
			currentStateImage = &normal;
		}

		return false;
	}

	void Button::draw(sf::RenderWindow *window) {
		currentStateImage->draw(window);
	}
}