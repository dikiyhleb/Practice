#include "user.h"
#include "generationNickname.h"
#include "generationPassword.h"
user::user() {}
user::user(const string& userNickname, const string& userPassword) {
	this->userNickname = userNickname;
	this->userPassword = userPassword;
}

// Создание имени пользователя самостоятельно
string user::createUserNicknameByYourself() {
	string userNickname;
	cout << "Введите имя пользователя на английском языке:" << endl;
	getline(cin, userNickname);
	if (userNickname.empty()) {
		cout << "Имя пользователя не может быть пустым!" << endl;
		return;
	}
	cout << "Имя пользователя создано!" << endl;
	return userNickname;
}

// Создание имени пользователя с помощью генерации имен
string user::createUserNicknameByGenerating() {
	string userName;
	string userNickname;
	cout << "Введите ваше имя на английском языке, чтобы имя пользователя сгенерировалось случайным образом:" << endl;
	getline(cin, userName);
	cout << " Вариация генераций " << '\n';
	cout << "1 вариант: " << genNicknameByBase() << '\n';
	cout << "2 вариант: " << genNicknameByBase() << '\n';
	cout << "3 вариант: " << genNicknameByBase() << '\n';
	int choice;
	cout << "Выберите номер варианта имени пользователя (1-3): ";
	cin >> choice;
	switch (choice) {
	case 1:
		userNickname = genNicknameByBase();
		break;
	case 2:
		userNickname = genNicknameByBase();
		break;
	case 3:
		userNickname = genNicknameByBase();
		break;
	default:
		cout << "Неверный выбор. Имя пользователя не создано." << endl;
		break;
	}
	cout << "Имя пользователя создано!" << endl;
	return userNickname;
}

// Создание пароля пользователя самостоятельно
string user::createUserPasswordByYourself() {
	string userPassword;
	cout << "Создайте пароль для вашего пользователя" << endl;
	getline(cin, userPassword);
	cout << "Пароль создан!" << endl;
	return userPassword;
}

// Создание пароля пользователя с помощью генерирования пароля
string user::createUserPasswordByGenerating() {
	generationPassword genPass;
	string userPassword;
	userPassword = genPass.generate();
	cout << "Пароль создан!" << endl;
	return userPassword;
}
 
 // Вывод данных пользователя
void user::displayUserInfo(vector <user>& users) {
	for (const auto& user : users) {
		cout << "Имя пользователя: " << userNickname << endl;
		if (userPassword.empty()) {
			break;
		}
		cout << "Пароль: " << userPassword << endl << endl;
	}
}

// Меню авторизации
void user::displayAuthMenu() {
	string nickname, password;
	cout << "Введите имя вашего пользователя: " << endl;
	getline(cin,nickname);
	cout << "Введите ваш пароль: " << endl;
	getline(cin, password);
	if (nickname == userNickname && password == userPassword) {
		cout << "Вход выполнен. Добро пожаловать, " << userNickname << "!\n";
	}
	else {
		cout << "Вход не выполнен. Неверное имя или пароль!\n";
	}
}

// Меню регистрации
void user::displayRegistrationMenu() {
	cout << "..........Меню создания пользователя.........." << endl;
	cout << "Создайте имя пользвателя" << endl;
	cout << "Варианты создания имени пользователя:" << endl << "1. Самостоятельно" << endl << "2. С помощью генерации имен" << endl;
	int choice;
	cout << "Выберите удобный вам вариант: " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		createUserNicknameByYourself();
		break;
	case 2:
		createUserNicknameByGenerating();
		break;
	default:
		cout << "Неверный выбор!" << endl;
		break;
	}
	cout << "Создайте пароль" << endl;
	cout << "Варианты создания пароля:" << endl << "1. Самостоятельно" << endl << "2. С помощью генерации пароля" << endl;
	int choice1;
	cout << "Выберите удобный вам вариант: " << endl;
	cin >> choice1;
	switch (choice1)
	{
	case 1:
		createUserPasswordByYourself();
		break;
	case 2:
		createUserPasswordByGenerating();
		break;
	default:
		cout << "Неверный выбор!" << endl;
		break;
	}
	users.push_back(user(userNickname, userPassword));
	cout << "Пользователь успешно создан!" << endl;
}
