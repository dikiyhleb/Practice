#pragma once
#ifndef GENERATIONNICKNAME_H
#define GENERATIONNICKNAME_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

string genNicknameByBase() {
	ifstream file("nicknameBase.txt");
	string line;
	vector<string> lines;

	if (file.is_open()) {
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();

		if (!lines.empty()) {
			srand(time(0));
			int randomIndex = rand() % lines.size();
			return lines[randomIndex];
		}
		else {
			return "File is empty.";
		}
	}
	else {
		return "Unable to open file.";
	}

}

#endif
