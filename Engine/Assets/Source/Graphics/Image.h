#pragma once
#include"IDrawable.h"
#include<string>
#include<memory>
#include<SFML\Graphics\Texture.hpp>
#include<SFML\Graphics\Sprite.hpp>
#include"..\Math\Point.h"

namespace sp {
	class Image : IDrawable {
		sp::Point position;
		std::shared_ptr<sf::Texture> pTexture;
		sf::Sprite sprite;

		struct uvs;

	public:
		Image();
		~Image();
		Image& operator=(const Image& other);

		void init(std::shared_ptr<sf::Texture> pTexture);
		void setUVs(int x, int y, int w, int h);
		
		std::string getPath();
		sf::Sprite* getSprite();
	};
}




/*
#pragma once

#include<string>
#include<SFML\Graphics.hpp>
#include<iostream>
#include"..\System\Window.h"
#include"..\Math\Point.h"


namespace sp {
	class Image {
		sf::Texture texture;
		sp::Point pos;
		sf::Sprite sprite;
	public:
		Image();
		Image(std::string filePath, sp::Point pos);
		Image(std::string filePath, sf::IntRect crop);
		Image(std::string filePath, sf::IntRect crop, sp::Point pos);

		void init(std::string filePath, sp::Point pos);
		void init(std::string filePath, sp::Point, sf::IntRect crop);

		void resize(float factorX, float factorY);

		sf::Sprite *getSprite();

		void setPosition(sp::Point pos);
		void draw(sp::Window *window);
	};
}
*/