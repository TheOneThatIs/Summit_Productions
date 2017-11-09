#include "ITile.h"
#include<iostream>


namespace sp {

	ITile::ITile(int id, int durability, sp::Image image) :
		i_ID(id), i_durability(durability), i_damage(0), i_image(image) {

	}
	ITile::~ITile() {

	}


	BlockState ITile::damage(float damage) {
		i_damage += damage;
		if (damage >= i_durability)
			return BlockState::BROKEN;
	}

	void ITile::onDestroy() {
		std::cout << "Tile ID: " << i_ID << "destroyed!" << std::endl;
	}

	void ITile::update() {

	}

	void ITile::setPosition(float x, float y) {
		i_image.setPosition( {x, y} );
	}

	int ITile::getID() {
		return i_ID;
	}

	int ITile::getDurability() {
		return i_durability;
	}

	int ITile::getDamage() {
		return i_damage;
	}

	sp::Image ITile::getImage() {
		return i_image;
	}
}