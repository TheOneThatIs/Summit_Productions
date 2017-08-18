#pragma once
#include<string>
#include<fstream>


namespace summit {
	class FileManager {

	public:
		FileManager();

		bool emptyFile(std::string filePath);

		void loadFile(std::string filePath);

		bool write(std::string filePath, std::string content);

		bool read(std::string filePath);
		bool read(std::string filePath, std::string variable);

		void toString();

		void fileLoadingError(std::string filePath);
	};
}