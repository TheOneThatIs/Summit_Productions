#include "Block.h"
#include<iostream>


namespace sp {
	Block::Block() {}


	void Block::setID(int id) {
		this->id = id;
	}

	int Block::getID() {
		return id;
	}
}