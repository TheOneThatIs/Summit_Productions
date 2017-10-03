#include "World.h"


namespace sp {
	World::World() {

	}
	World::~World() {

	}


	void World::registerEntity(Entity* entity) {
		for (int i = 0; i < entityRegistry.size(); i++) {
			if (entityRegistry[i]->getID() == entity->getID()) {
				std::cout << "[ERROR] An entity with ID " << entity->getID() << " is already in use! Please use another ID." << std::endl;
				break;
			}
		}

		entityRegistry.push_back(entity);
	}

	void World::registerTile(Tile* tile) {
		for (int i = 0; i < tileRegistry.size(); i++) {
			if (tileRegistry[i]->getID() == tile->getID()) {
				std::cout << "[ERROR] A tile with ID " << tile->getID() << " is already in use! Please use another ID." << std::endl;
				break;
			}
		}

		tileRegistry.push_back(tile);
	}

	void World::registerTileMap(TileMap* map) {
		for (int i = 0; i < mapRegistry.size(); i++) {
			if (mapRegistry[i]->getID() == map->getID()) {
				std::cout << "[ERROR] A map with ID " << map->getID() << " is already in use! Please use another ID." << std::endl;
				break;
			}
		}
		map->loadMap(map->getFilePath(), tileRegistry);

		mapRegistry.push_back(map);
	}



	void World::update(sf::Event& event){
		currentMap.update(event);
	}

	void World::draw(Window *window) {
		currentMap.draw(window);
	}

	void World::useMap(int i) {
		currentMap = *mapRegistry[i];
	}
}
//namespace sp {
//	World::World() {}
//
//
//	bool World::registerBlock(int id, Block *block) {
//		for (int i = 0; i < blockRegistry.size(); i++) {
//			if (id == blockRegistry[i]->getID()) {
//				std::cout << "*** Block ID " << id << " is already in use! Please pick another ID.***" << std::endl;
//				return false;
//			}
//		}
//
//		block->setID(id);
//		blockRegistry.push_back(block);
//		std::cout << block->getID() << std::endl;
//		return true;
//	}
//
//	std::vector<Block*>* World::getBlockRegistry() {
//		return &blockRegistry;
//	}
//
//	void World::draw(Window *window) {
//		currentMap->draw(window);
//
//		for (int i = 0; i < entities.size(); i++)
//			entities[i]->draw(window);
//	}
//
//	void World::update() {
//		currentMap->update();
//
//		for (int i = 0; i < entities.size(); i++)
//			;// entities[i]->update();
//	}
//
//	bool World::spawn(Entity *entity, float x, float y) {
//		entity->setPos(x, y);
//		entities.push_back(entity);
//
//		return false;
//	}
//
//	void World::setMap(Map *map) {
//		currentMap = map;
//	}
//	bool World::saveMap() {
//		return false;
//	}
//}