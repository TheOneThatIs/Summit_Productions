#pragma once
#include<vector>
#include"ITile.h"
#include"ITileBatch.h"

namespace sp {
	class TileMap{
		int width, height;
		int tileWidth, tileHeight;
		ITileBatch* tileBatch;

		std::vector< std::vector<ITile*> > tiles;

	public:
		TileMap();
		~TileMap();

		void draw(sp::Window *window);
		void update();

		void resize(int width, int height);
		void setTileSize(int width, int height);

		void load(std::string filepath);
		void save(std::string filepath);

		void bindTileBatch(ITileBatch* tileBatch);
	};
}