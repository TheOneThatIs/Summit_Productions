#include "TileMap.h"
#include<fstream>

namespace sp {
	TileMap::TileMap() {}
	TileMap::~TileMap() {}

	void TileMap::draw(sp::Window *window) {
		for (int i = 0; i < tiles.size(); i++)
			for (int j = 0; j < tiles.size(); j++)
				tiles[i][j]->draw(window);
	}
	void TileMap::update() {
		
	}

	void TileMap::resize(int width, int height) {
		this->width = width;
		this->height = height;
	}

	void TileMap::setTileSize(int width, int height) {
		tileWidth = width;
		tileHeight = height;
	}

	void TileMap::load(std::string filepath){
		if (tileBatch != nullptr) { // Make sure the user has bound their tileBatch
			std::ifstream file(filepath);
			std::string line;
			std::string strNum = "";
			int row = 0;
			int column = 0;

			tiles.resize(width);
			for (int i = 0; i < tiles.size(); i++) {
				tiles[i].resize(height);
			}

			while (std::getline(file, line)) {
				for (int i = 0; i < line.size() + 1; i++) {
					if (line[i] != ',' && line[i] != '\0')
						strNum += line[i];
					else if (line[i] == ',' || line[i] == '\0') {
						// *** Store strNum in TileMap here ***

						tiles[row][column] = tileBatch->createTile(std::stoi(strNum));
						tiles[row][column]->setPosition(row*tileWidth, column*tileHeight);

						strNum = "";
						row++;
						continue;
					}
				}
				row = 0;
				column++;
			}
		}
	}

	void TileMap::save(std::string filepath){
		
	}

	void TileMap::bindTileBatch(ITileBatch* tileBatch) {
		this->tileBatch = tileBatch;
	}
}