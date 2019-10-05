#include"fileLib.h"

bool isValidFile(std::ifstream &fin, std::string &error) {
	if (fin) {
		fin.seekg(0, std::ios::end);
		if (fin.tellg() != 0) {
			fin.seekg(0, std::ios::beg);
			return 1;
		}
		else {
			error = "The file is empty";
			return 0;
		}
	} else {
		error = "The file is not found";
		return 0;
	}
}