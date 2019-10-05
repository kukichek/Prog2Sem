#pragma once
#include<fstream>
#include<string>
#include"Numbers.h"
#include"fileLib.h"

using namespace std;

class Extractor {
	ifstream fin;
public:
	Extractor(string nameOfFile);
	Numbers createNumList();
};