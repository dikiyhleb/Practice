#include "user.h"
#include "generationNickname.h"
#include "generationPassword.h"
//setlocale(LC_ALL, "RU");
using namespace std;
user::user() {}
user::user(const string& userNickname, const string& userPassword) {
	this->userNickname = userNickname;
	this->userPassword = userPassword;
}

// Создание имени пользователя самостоятельно
string user::createUserNicknameByYourself() {
	string userNickname;
	cout << "Введите имя пользователя на английском языке: ";
	cin >> userNickname;
	if (userNickname.empty()) {
		cout << "Имя пользователя не может быть пустым!" << endl;
		return ""; 
	}
	return userNickname;
}

// Создание имени пользователя с помощью генерации имен
string user::createUserNicknameByGenerating() {
	string userName;
	string userNickname;
	cin >> userName;
	cout << "Вариация генераций: " << '\n';
	cout << "1. " << genNicknameByBase() << '\n';
	cout << "2. " << genNicknameByBase() << '\n';
	cout << "3. " << genNicknameByBase() << '\n';
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
	cout << "Имя пользователя задано!\n" << endl;
	return userNickname;
}

// Создание пароля пользователя самостоятельно
string user::createUserPasswordByYourself() {
	string userPassword;
	cout << "Придумайте пароль: " << endl;
	cin >> userPassword;
	cout << "Пароль создан!\n" << endl;
	return userPassword;
}

// Создание пароля пользователя с помощью генерирования пароля
string user::createUserPasswordByGenerating() {
	generationPassword genPass;
	string userPassword;
	userPassword = genPass.generate();
	cout << "Пароль создан! Ваш пароль: " << userPassword << endl;
	return userPassword;
}
 
 // Вывод данных пользователя
void user::displayUserInfo(vector <user>& users) {
	for (const user& User : users) {
		cout << "Имя пользователя: " << User.userNickname << endl;
	/*	if (userPassword.empty()) {
			break;
		}
		cout << "Пароль: " << userPassword << endl << endl; */
	}
	return;
}

// Меню авторизации
void user::displayAuthMenu(vector<user>& users) {
	string nickname, password;
	cout << "Введите имя вашего пользователя: " << endl;
	cin >> nickname;

	bool userFound = false;

	for (const auto& User : users) {
		if (User.userNickname == nickname) {
			userFound = true;

			cout << "Введите ваш пароль: " << endl;
			cin >> password;

			if (User.userPassword == password) {
				cout << "Вход выполнен. Добро пожаловать, " << User.userNickname << "!\n";
			}
			else {
				cout << "Вход не выполнен. Неверное имя или пароль!\n";
			}
			break;
		}
	}

	if (!userFound) {
		cout << "Пользователь с таким именем не найден! " << endl;
	}
}
// Меню регистрации
void user::displayRegistrationMenu() {
	cout << "\n..........Меню создания пользователя.........." << endl;
	cout << "Варианты создания имени пользователя:" << endl << "1. Самостоятельно" << endl << "2. С помощью генерации имен" << endl << "3. Выход" << endl;
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
	case 3:
		break;
	default:
		cout << "Неверный выбор!" << endl;
		break;
	}
	cout << "Создайте пароль" << endl;
	cout << "Варианты создания пароля:" << endl << "1. Самостоятельно" << endl << "2. С помощью генерации пароля" << endl << "3. Выход" << endl;
	int choice1;
	cout << "Выберите удобный вам вариант: ";
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
	cout << "Аккаунт успешно создан!\n" << endl;
}
