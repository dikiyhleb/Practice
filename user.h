#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <string>

class user {
private:
	std::string userNickname;
	std::string userPassword;
	std::vector <user> users;
public:
	user();
	user(const std::string& userNickname, const std::string& userPassword);
	std::string createUserNicknameByYourself();
	std::string createUserNicknameByGenerating();
	std::string createUserPasswordByYourself();
	std::string createUserPasswordByGenerating();
	void displayUserInfo(std::vector <user>& users);
	void displayAuthMenu(std::vector <user>& users);
	void displayRegistrationMenu(std::vector<user>& users);
};

#endif
