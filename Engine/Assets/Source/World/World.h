#pragma once
#include<vector>
#include"Entity.h"
#include"TileMap.h"


namespace sp {
	class World {
		std::vector<Tile*> tileRegistry;
		std::vector<TileMap*> mapRegistry;
		std::vector<Entity*> entityRegistry;

		TileMap currentMap;

	public:
		World();
		~World();

		void registerEntity(Entity* entity);
		void registerTile(Tile* tile);
		void registerTileMap(TileMap* map);

		void update(sf::Event &event);
	};
}
//namespace sp {
//	class World {
//		std::vector<Entity*> entities;
//		Map *currentMap;
//
//	public:
//		std::vector<Block*> blockRegistry;
//		World();
//
//
//		bool registerBlock(int id, Block *block);
//		std::vector<Block*>* getBlockRegistry();
//		void draw(Window *window);
//		void update();
//
//		bool spawn(Entity *entity, float x, float y);
//		
//		void setMap(Map *map);
//		bool saveMap();
//	};
//}