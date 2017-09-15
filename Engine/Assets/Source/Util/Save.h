#pragma once
#include"File.h"
#include<vector>


namespace sp {
	class Save {
		File file;
		std::vector<float*> floats;
		std::vector<std::string> floatNames;
		std::vector<int*> ints;
		std::vector<std::string> intNames;
		std::vector<std::string*> strings;
		std::vector<std::string> stringNames;
		std::vector<bool*> bools;
		std::vector<std::string> boolNames;

	public:
		Save();
		Save(std::string filePath);

		void associateFile(std::string filePath);

		void registerFloat(std::string varName, float *f);
		void registerInt(std::string varName, int *i);
		void registerString(std::string varName, std::string *s);
		void registerBool(std::string varName, bool *b);

		void save();
		void load();

	};
}