#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <string>

class user {
private:
	std::string userNickname;
	std::string userPassword;
public:
	user();
	std::string createUserNicknameByYourself();
	std::string createUserNicknameByGenerating();
	std::string createUserPasswordByYourself();
	std::string createUserPasswordByGenerating();
	void editUserInfo();
	void displayUserInfo();
	void displayAuthMenu();
	void displayRegistrationMenu();
};

#endif
