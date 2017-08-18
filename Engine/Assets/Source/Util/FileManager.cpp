#include"FileManager.h"
#include<iostream>
#include<sstream>


namespace summit {

	FileManager::FileManager() {

	}


	void FileManager::loadFile(std::string filePath) {
		
	}

	bool FileManager::emptyFile(std::string filePath) {
		std::ofstream file(filePath, std::ios::trunc);
		
		if (file.is_open()) {
			file.close();
			return true;
		}
		else {
			fileLoadingError(filePath);
			return false;
		}
	}

	bool FileManager::write(std::string filePath, std::string content) {
		std::ofstream file(filePath, std::ios::app);

		if (file.is_open()) {
			file << content;

			file.close();
			return true;
		}
		else {
			fileLoadingError(filePath);
			return false;
		}
	}

	bool FileManager::read(std::string filePath) {
		return false;
	}
	bool FileManager::read(std::string filePath, std::string variable) {
		return false;
	}

	void FileManager::toString() {
		
	}

	void FileManager::fileLoadingError(std::string filePath) {
		std::cout << "Cannot load file \"" + filePath + "\"" << std::endl;
	}
}