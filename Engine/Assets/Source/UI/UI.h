#pragma once

#include<SFML\Graphics.hpp>

namespace summit {
	class UI {
	protected:
		sf::RenderWindow *window;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f pos;
	public:
		UI(){}

		void setPosition(sf::Vector2f pos) { this->pos = pos; sprite.setPosition(pos); } // Sets exact position
		void move(float x, float y) {} // Adds param xy into UIs xy

		sf::Vector2f getPos() { return pos; }
	};

}