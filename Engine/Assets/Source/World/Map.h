#pragma once
#include"Block.h"
#include<vector>
#include"..\System\Window.h"


namespace sp {
	class Map {
		std::vector< std::vector<Block> > blocks;

	public:
		Map();

		void draw(Window *window);
		void update();

		bool loadMap(std::string filePath, std::vector<Block*> *blockRegistry);
		Block loadBlock(int id, std::vector<Block*> *blockRegistry);
	};
}