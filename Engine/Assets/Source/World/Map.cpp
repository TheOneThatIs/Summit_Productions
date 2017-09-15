#include"Map.h"
#include<iostream>
#include"..\Util\File.h"
#include<fstream>
#include<sstream>



namespace sp {
	Map::Map(){}


	void Map::draw(Window *window) {
		
	}

	void Map::update() {
		
	}

	bool Map::loadMap(std::string filePath, std::vector<Block*> *blockRegistry) {
		std::ifstream file(filePath);
		std::string line;
		int lineNum = 0;
		std::stringstream strStream;
		std::string strNum;

		while (std::getline(file, line)) {
			//std::cout << line << std::endl;

			for (int i = 0; i < line.size(); i++) { // Iterate through the line
				if (line[i] != ',') {
					std::string str;
					str = line[i];
					strNum.append(str);
				}
				else {
					blocks[lineNum][i] = loadBlock(stoi(strNum), blockRegistry);
					strNum = "";
				}
			}
			lineNum++;
		}

		return false;
	}

	Block Map::loadBlock(int id, std::vector<Block*> *blockRegistry) {
		for (int i = 0; i < blockRegistry->size(); i++) {
			if (blockRegistry->at(i)->getID() == id) // if it found the block relating to id
				return *blockRegistry->at(i); // return that block... or not...
		}
	}
}