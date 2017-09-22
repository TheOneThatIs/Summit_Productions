#pragma once
#include"Tile.h"
#include<vector>
#include"..\System\Window.h"


namespace sp {
	class TileMap {
		std::vector< std::vector<Tile*> > tiles;
		int id;
		std::string filePath;

	public:
		TileMap(int id, std::string filePath);
		TileMap();

		void draw(Window *window);
		void update(sf::Event& event);

		bool loadMap(std::string filePath, std::vector<Tile*> &tileRegistry);
		Tile loadTile(int id, std::vector<Tile*> &tileRegistry);

		int getID();
		std::string getFilePath();
	};
}