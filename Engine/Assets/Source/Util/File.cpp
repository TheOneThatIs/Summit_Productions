#include"File.h"
#include<iostream>
#include<sstream>
#include<vector>

namespace sp {

	File::File(): file(""), position(0){}

	File::File(std::string filePath) {
		this->filePath = filePath;
	}


	void File::associateFile(std::string filePath) {
		this->filePath = filePath;
		file.open(filePath);
	}

	bool File::emptyFile() {
		if (filePath == "") {
			std::cout << "No file on disk is associated to virtual file. Please use 'File::associateFile(std::string filePath)' before performing operations on a file." << std::endl;
			return false;
		}
			
		std::ofstream file(filePath, std::ios::trunc);
		
		if (file.is_open()) {
			file.close();
			return true;
		}
		else {
			fileLoadingError();
			return false;
		}
	}

	bool File::write(std::string data) {
		if (filePath == "") {
			std::cout << "No file on disk is associated to virtual file. Please use 'File::associateFile(std::string filePath)' before performing operations on a file." << std::endl;
			return false;
		}

		std::ofstream file(filePath, std::ios::app);

		if (file.is_open()) {
			file << data;

			file.close();
			return true;
		}
		else {
			fileLoadingError();
			return false;
		}
	}

	bool File::read() {
		if (filePath == "") {
			std::cout << "No file on disk is associated to virtual file. Please use 'File::associateFile(std::string filePath)' before performing operations on a file." << std::endl;
			return false;
		}

		return false;
	}
	
	std::string File::read(int position, char delimeter) {
		std::ifstream file(filePath);
		file.seekg(position);

		std::stringstream strStream;

		char currentChar;
		file.get(currentChar);

		while (currentChar != delimeter && currentChar != '\n') {
			strStream << currentChar;
			file.get(currentChar);
		}


		file.close();

		return strStream.str();
	}

	std::string File::read(std::string varName) {
		std::ifstream file(filePath);
		std::stringstream strStream;
		std::string line;
		

		while (getline(file, line)) {
			strStream.str("");
			for (int i = 0; i < varName.size(); i++) {
				if (line[i] == varName[i])
					strStream << line[i];
			}
			if (strStream.str() == varName) {
				strStream.str("");

				int i = varName.size() + 1;
				while (line[i] != '\0') {
					strStream << line[i];
					i++;
				}

				return strStream.str();
			}
		}
		return "Can't find varName: \"" + varName + "\"";
	}

	std::streampos File::getPosition() {
		return position;
	}


	float File::loadfloat(std::string varName) {
		if (filePath == "") {
			std::cout << "No file on disk is associated to virtual file. Please use 'File::associateFile(std::string filePath)' before performing operations on a file." << std::endl;
			return false;
		}

		std::ifstream file(filePath);
		std::string line;
		int pos = 0;

		if (file.is_open()) {
			while (getline(file, line)){
				int linePos = line.find(varName);

				if (linePos != std::string::npos) {
					std::cout << read(pos + linePos, '\n') << std::endl;
					return 0.0f;
				}

				pos += line.length() + 1;
			}

			file.close();
		} else {
			fileLoadingError();
			return 0.0f;
		}
	}

	float File::strToFloat(std::string str) {
		try {
			return std::stof(str);
		}
		catch (...) {
			std::cout << "Error caught: " << "\"" << str << "\"" << " is not a float!" << std::endl;
		}
	}

	int File::strToInt(std::string str) {
		try {
			return std::stoi(str);
		}
		catch (...) {
			std::cout << "Error caught: " << "\"" << str << "\"" << " is not a int!" << std::endl;
		}
	}

	bool File::strToBool(std::string str){
		try {
			return (bool)std::stoi(str);
		}
		catch (...) {
			std::cout << "Error caught: " << "\"" << str << "\"" << " is not a bool!" << std::endl;
		}
	}

	void File::fileLoadingError() {
		std::cout << "Cannot load file \"" + filePath + "\"" << std::endl;
	}
}