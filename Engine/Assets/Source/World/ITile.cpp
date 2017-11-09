#include "ITile.h"
#include<iostream>


namespace sp {

	ITile::ITile(int id, int durability) :
		i_ID(id), i_durability(durability), i_damage(0){

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

	int ITile::getID() {
		return i_ID;
	}

	int ITile::getDurability() {
		return i_durability;
	}

	int ITile::getDamage() {
		return i_damage;
	}
}