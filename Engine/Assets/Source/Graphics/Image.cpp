#include"Image.h"
#include"TextureCache.h"
#include<iostream>


namespace sp {
	struct Image::uvs {
		int x = 0, y = 0;
		int w = 10, h = 10;
	}UVs;


	Image::Image() {
		
	}
	Image::~Image() {
		std::cout << "Destroying image..." << std::endl;
	}

	void Image::init(std::shared_ptr<sf::Texture> pTexture) {
		if (pTexture == nullptr)
			std::cout << "Could not load texture" << std::endl;
		else {
			this->pTexture = pTexture;
			sprite.setTexture(*pTexture);
			sprite.setTextureRect({ UVs.x, UVs.y, UVs.w, UVs.h });
		}
	}

	void Image::setUVs(int x, int y, int w, int h) {
		UVs.x = x;
		UVs.y = y;
		UVs.w = w;
		UVs.h = h;
	}

	std::string Image::getPath() {
		//*** TODO ***
		return nullptr;
	}

	sf::Sprite* Image::getSprite() {
		return &sprite;
	}
}





/*
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
		setPosition({ 0, 0 });
	}
	Image::Image(std::string filePath, sf::IntRect crop, sp::Point pos) {
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
*/