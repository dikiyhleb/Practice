#pragma once
#include <iostream>
#include <string>

using namespace std;

string genNickname(string defaultNick) {
	for (int i = 1; i < defaultNick.length(); i++) {
		switch (defaultNick[i])
		{
		case 'I':
		case 'i':
			defaultNick[i] = '1';
			break;
		case 'A':
		case 'a':
			defaultNick[i] = '4';
			break;
		case 'G':
		case 'g':
			defaultNick[i] = '6';
			break;
		case 'B':
		case 'b':
			defaultNick[i] = '8';
			break;
		case 'O':
		case 'o':
			defaultNick[i] = '0';
			break;
		default:
			break;
		}
		i++;
	}
	return defaultNick;
}