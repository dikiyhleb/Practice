#pragma once
#include <iostream>
#include <string>

using namespace std;

string genNickname(string defaultNick) {
	for (int i = 1; i < defaultNick.length(); i++) {
		int count = 0;
		while (count < 2)
		{
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
			default:
				break;
			}
			count++;
		}
	}
	return defaultNick;
}