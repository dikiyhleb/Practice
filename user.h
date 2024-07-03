#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <Windows.h>
using namespace std;

class user {
public:
    user();
    user(const string& userNickname, const string& userPassword);

    string createUserNicknameByYourself();
    string createUserNicknameByGenerating();
    string createUserPasswordByYourself();
    string createUserPasswordByGenerating();

    void displayUserInfo(vector<user>& users);
    void displayAuthMenu(vector<user>& users);
    void displayRegistrationMenu(vector<user>& users);
    void handleUserChoice(int choice, vector<user>& users); // Новый метод

private:
    string userNickname;
    string userPassword;
};
