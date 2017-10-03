#include"TileMap.h"
#include<iostream>
#include"..\Util\File.h"
#include<fstream>
#include<sstream>



namespace sp {
	TileMap::TileMap(int id, std::string filePath) {
		this->id = id;
		this->filePath = filePath;
	}

	TileMap::TileMap() { id = 0; }


	void TileMap::draw(Window *window) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				tiles[i][j]->draw(window);
	}

	void TileMap::update(sf::Event& event) {
		
	}

	bool TileMap::loadMap(std::string filePath, std::vector<Tile*> &tileRegistry) {
		std::ifstream file(filePath);
		std::string line;
		int currentLine = 0;
		std::string strNum;
		int tileIndex = 0;

		while (std::getline(file, line)) {
			tileIndex = 0;
			for (int i = 0; i < line.size()+1; i++) { // Iterate through the line
				if (line[i] != ',' && line[i] != '\0') {
					strNum += line[i];
				}
				else {
					//tiles.resize(tileIndex);
					//tiles[currentLine][tileIndex] = loadTile(tileRegistry[tileIndex]->getID(), tileRegistry);
					tiles[currentLine][tileIndex] = loadTile(stoi(strNum), tileRegistry);
					tiles[currentLine][tileIndex]->setPosition(tiles[currentLine][tileIndex]->getWidth()*tileIndex, tiles[currentLine][tileIndex]->getHeight()*currentLine);
					strNum = "";
					tileIndex++;
				}
			}
			currentLine++;
		}

		return false;
	}

	//bool TileMap::loadMap(std::string filePath, std::vector<Tile*> &tileRegistry) {
	//	std::ifstream file(filePath);
	//	std::string line;
	//	int lineNum = 0;
	//	std::stringstream strStream;
	//	std::string strNum;
	//	tiles.resize(100);
	//	while (std::getline(file, line)) {
	//		//std::cout << line << std::endl;
	//		for (int i = 0; i < line.size(); i++) { // Iterate through the line
	//			tiles[i].resize(100);
	//			if (line[i] != ',') {
	//				std::string str;
	//				str = line[i];
	//				strNum.append(str);
	//			}
	//			else {
	//				
	//				tiles[lineNum][i];   //push_back(loadTile(stoi(strNum), tileRegistry));
	//					strNum = "";
	//			}
	//		}
	//		lineNum++;
	//	}
	//	for (int i = 0; i < tiles.size(); i++) {
	//		for (int j = 0; j < tiles.size(); j++) {
	//			std::cout << tiles[i][j]->getID() << ", ";
	//		}
	//		std::cout << std::endl;
	//	}
	//	return false;
	//}

	Tile* TileMap::loadTile(int id, std::vector<Tile*> &tileRegistry) {
		for (int i = 0; i < tileRegistry.size(); i++) {
			if (tileRegistry[i]->getID() == id) {
				return tileRegistry[i];
			}
		}
	}

	//Tile TileMap::loadTile(int id, std::vector<Tile*> &tileRegistry) {
	//	for (int i = 0; i < tileRegistry.size(); i++) {
	//		if (tileRegistry.at(i)->getID() == id) { // if it found the block relating to id
	//			//tileRegistry.at(i).
	//			return *tileRegistry.at(i); // return that tile... or not...
	//		}
	//	}
	//}

	int TileMap::getID() {
		return id;
	}

	std::string TileMap::getFilePath() {
		return filePath;
	}
}