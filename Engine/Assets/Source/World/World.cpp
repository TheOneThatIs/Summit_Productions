#include "World.h"


namespace sp {
	World::World() {}


	bool World::registerBlock(int id, Block *block) {
		for (int i = 0; i < blockRegistry.size(); i++) {
			if (id == blockRegistry[i]->getID()) {
				std::cout << "*** Block ID " << id << " is already in use! Please pick another ID.***" << std::endl;
				return false;
			}
		}

		block->setID(id);
		blockRegistry.push_back(block);
		std::cout << block->getID() << std::endl;
		return true;
	}

	std::vector<Block*>* World::getBlockRegistry() {
		return &blockRegistry;
	}

	void World::draw(Window *window) {
		currentMap->draw(window);

		for (int i = 0; i < entities.size(); i++)
			entities[i]->draw(window);
	}

	void World::update() {
		currentMap->update();

		for (int i = 0; i < entities.size(); i++)
			entities[i]->update();
	}

	bool World::spawn(Entity *entity, float x, float y) {
		entity->setPos(x, y);
		entities.push_back(entity);

		return false;
	}

	void World::setMap(Map *map) {
		currentMap = map;
	}
	bool World::saveMap() {
		return false;
	}
}