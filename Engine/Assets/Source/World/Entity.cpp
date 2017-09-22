#include"Entity.h"

namespace sp {
	Entity::Entity(int id) { setID(id); }
	Entity::~Entity() {}


	void Entity::uponCreation() {

	}
	void Entity::update(sf::Event &event) {

	}
	void Entity::draw(sp::Window *window) {

	}
	void Entity::uponDestruction() {

	}

	void Entity::setID(int id) {
		this->id = id;
	}

	int Entity::getID() {
		return id;
	}

	void Entity::setPos(float x, float y) {
		pos = Point(x, y);
	}

	Point Entity::getPos() {
		return pos;
	}
}