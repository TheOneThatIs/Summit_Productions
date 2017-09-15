#pragma once
#include<string>
#include<fstream>



namespace sp {
	class File {
		std::string filePath;
		std::streampos position;
		std::fstream file;

	public:
		File();
		File(std::string filePath);

		void associateFile(std::string filePath);

		bool emptyFile();

		bool write(std::string data);

		bool read();
		std::string read(int position, char delimeter);
		std::string read(std::string varName);

		std::streampos getPosition();

		float loadfloat(std::string varName);

		float strToFloat(std::string str);
		int strToInt(std::string str);
		bool strToBool(std::string str);

		void fileLoadingError();
	};
}