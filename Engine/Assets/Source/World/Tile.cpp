#include "Tile.h"
#include<iostream>


namespace sp {
	Tile::Tile(int id) { setID(id); }


	void Tile::setID(int id) {
		this->id = id;
	}

	void Tile::setTexture(std::string filePath) {
		texture.init(filePath, pos);
	}

	int Tile::getID() {
		return id;
	}

	void Tile::draw(Window *window) {
		texture.draw(window);
	}

	void Tile::setPosition(float x, float y) {
		pos.x = x;
		pos.y = y;
		texture.setPosition(Point(x, y));
	}

	float Tile::getWidth() {
		return width;
	}
	float Tile::getHeight() {
		return height;
	}

	void Tile::setDimensions(float width, float height) {
		this->width = width;
		this->height = height;
	}
}