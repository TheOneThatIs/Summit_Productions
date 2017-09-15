#pragma once
#include<vector>
#include"Map.h"
#include"Entities\Entity.h"
#include"..\System\Window.h"
#include"Block.h"



namespace sp {
	class World {
		std::vector<Entity*> entities;
		Map *currentMap;

	public:
		std::vector<Block*> blockRegistry;
		World();


		bool registerBlock(int id, Block *block);
		std::vector<Block*>* getBlockRegistry();
		void draw(Window *window);
		void update();

		bool spawn(Entity *entity, float x, float y);
		
		void setMap(Map *map);
		bool saveMap();
	};
}