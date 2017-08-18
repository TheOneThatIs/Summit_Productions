#include"Image.h"



namespace summit {
	
	Image::Image() {}

	Image::Image(std::string filePath, sf::Vector2f pos){
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);
		setPosition(pos);
	}


	void Image::init(std::string filePath, sf::Vector2f pos) {
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);
		setPosition(pos);
	}

	void Image::init(std::string filePath, sf::Vector2f pos, sf::IntRect crop) {
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);
		sprite.setTextureRect(crop);
		setPosition(pos);
	}

	void Image::resize(float factorX, float factorY){
		sprite.scale(sf::Vector2f(factorX, factorY));
	}

	void Image::setPosition(sf::Vector2f pos) {
		this->pos = pos;
		sprite.setPosition(pos);
		
	}

	sf::Sprite* Image::getSprite() { return &sprite; }

	void Image::draw(Window *window) {
		window->draw(sprite);
	}


}