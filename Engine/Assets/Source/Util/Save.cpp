#include"Save.h"


namespace sp {

	Save::Save() {

	}
	Save::Save(std::string filePath) {
		file.associateFile(filePath);
	}


	void Save::associateFile(std::string filePath) {
		file.associateFile(filePath);
	}


	void Save::registerFloat(std::string varName, float *f) {
		floatNames.push_back(varName);
		floats.push_back(f);
	}
	void Save::registerInt(std::string varName, int *i) {
		intNames.push_back(varName);
		ints.push_back(i);
	}
	void Save::registerString(std::string varName, std::string *s) {
		stringNames.push_back(varName);
		strings.push_back(s);
	}
	void Save::registerBool(std::string varName, bool *b) {
		boolNames.push_back(varName);
		bools.push_back(b);
	}

	void Save::save() {
		file.emptyFile();

		for (int i = 0; i < floats.size(); i++)
			file.write(floatNames[i] + "=" +  std::to_string(*floats[i]) + "\n");
		for (int i = 0; i < ints.size(); i++)
			file.write(intNames[i] + "=" + std::to_string(*ints[i]) + "\n");
		for (int i = 0; i < strings.size(); i++)
			file.write(stringNames[i] + "=" + *strings[i] + "\n");
		for (int i = 0; i < bools.size(); i++)
			file.write(boolNames[i] + "=" + std::to_string(*bools[i]) + "\n");
	}

	void Save::load() {
		for (int i = 0; i < floats.size(); i++)
			*floats[i] = file.strToFloat(file.read(floatNames[i]));
		for (int i = 0; i < ints.size(); i++)
			*ints[i] = file.strToInt(file.read(intNames[i]));
		for (int i = 0; i < strings.size(); i++)
			*strings[i] = file.read(stringNames[i]);
		for (int i = 0; i < bools.size(); i++)
			*bools[i] = file.strToBool(file.read(boolNames[i]));
	}
}