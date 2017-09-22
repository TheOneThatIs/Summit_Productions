#include "Tile.h"
#include<iostream>


namespace sp {
	Tile::Tile(int id) { setID(id); }


	void Tile::setID(int id) {
		this->id = id;
	}

	void Tile::setTexture(std::string filePath) {
		Image image;
		image.init(filePath, pos);
	}

	int Tile::getID() {
		return id;
	}

	void Tile::draw(Window *window) {
		texture.draw(window);
	}
}