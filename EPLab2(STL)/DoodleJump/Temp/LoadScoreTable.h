#pragma once
#include <fstream>
#include <map>
#include <string>
#include"globalScore.h"

class ProcessScoreTable {
public:
	static void LoadScoreTable () {
		std::ifstream in("score/table.txt");

		string name;
		int nameScore;

		in.seekg(0, std::ios::end);
		if (in.tellg() != 0) {
			in.seekg(0, std::ios::beg);
			while (!in.eof()) {
				in >> name >> nameScore;
				scoreTable.emplace(name, nameScore);
			}
		}

		in.close();
	}
	static void SaveScoreTable() {
		std::ofstream out("score/table.txt");
		for (auto i: scoreTable) {
			out << i.first << ' ' << i.second << endl;
		}
		out.close();
	}
};