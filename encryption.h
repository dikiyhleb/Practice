#pragma once
#include <iostream>
#include <string>
using namespace std;

//Шифровка
string encrypt(string input) {
    const int number = input.size();
    string result = "";
    for (int i = 0; i < number; i++) {
        int symbol = input[i];
        symbol += 7;
        result += symbol;
    }
    return result;
}

//Дешифровка
string decrypt(string input) {
    const int number = input.size();
    string result = "";
    for (int i = 0; i < number; i++) {
        int symbol = input[i];
        symbol -= 7;
        result += symbol;
    }
    return result;
}
