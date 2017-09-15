#include"Entity.h"

namespace sp {
	Entity::Entity(int id) { setID(id); }


	void Entity::setID(int id) {
		this->id = id;
	}

	void Entity::setPos(float x, float y) {
		pos = Point(x, y);
	}

	Point Entity::getPos() {
		return pos;
	}
}