#include"Extractor.h"

Extractor::Extractor(string nameOfFile) {
	nameOfFile = "content\\" + nameOfFile;
	fin.open(nameOfFile);

	string error;
	if (!isValidFile(fin, error)) {
		fin.close();
		throw error;
	}
}
Numbers Extractor::createNumList() {
	Numbers _nums;
	int temp;

	while (fin >> temp) {
		_nums.push(temp);
	}

	return _nums;
}