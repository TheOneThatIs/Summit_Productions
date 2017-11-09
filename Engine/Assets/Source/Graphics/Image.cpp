#include"Image.h"



namespace sp {
	
	Image::Image() {}

	Image::Image(std::string filePath, sp::Point pos){
		texture.loadFromFile(filePath);
		sprite.setTexture(texture);
		setPosition(pos);
	}
	Image::Image(std::string filePath, sf::IntRect crop) {
		if (!texture.loadFromFile(filePath))
			std::cout << "Error loading file \"" << filePath << "\"" << std::endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(crop);
		setPosition(pos);
	}


	void Image::init(std::string filePath, sp::Point pos) {
		if(!texture.loadFromFile(filePath))
			std::cout << "Error loading file \"" << filePath << "\"" << std::endl;
		sprite.setTexture(texture);
		setPosition(pos);
	}

	void Image::init(std::string filePath, sp::Point pos, sf::IntRect crop) {
		if (!texture.loadFromFile(filePath))
			std::cout << "Error loading file \"" << filePath << "\"" << std::endl;
		sprite.setTexture(texture);
		sprite.setTextureRect(crop);
		setPosition(pos);
	}

	void Image::resize(float factorX, float factorY){
		sprite.scale(sf::Vector2f(factorX, factorY));
	}

	void Image::setPosition(sp::Point pos) {
		this->pos = pos;
		sprite.setPosition(sf::Vector2f(pos.x, pos.y));
	}

	sf::Sprite* Image::getSprite() { return &sprite; }

	void Image::draw(Window *window) {
		window->draw(sprite);
	}

}