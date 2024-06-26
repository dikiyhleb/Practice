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
		case 'E':
		case 'e':
			defaultNick[i] = '3';
			break;
		case 'L':
		case 'l':
			defaultNick[i] = '1';
			break;
		case 'S':
		case 's':
			defaultNick[i] = '5';
			break;
		case 'T':
		case 't':
			defaultNick[i] = '7';
			break;
		case 'Z':
		case 'z':
			defaultNick[i] = '2';
			break;
		default:
			break;
		}
		i++;
	}
	return defaultNick;
}