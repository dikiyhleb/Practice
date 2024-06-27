#include "user.h"
#include "generationNickname.h"
#include "generationPassword.h"
user::user() {}

// Создание имени пользователя самостоятельно
string user::createUserNicknameByYourself() {
	string userNickname;
	cout << "Введите имя пользователя на английском языке:" << endl;
	getline(cin, userNickname);
	return userNickname;
}

// Создание имени пользователя с помощью генерации имен
string user::createUserNicknameByGenerating() {
	string userName;
	string userNickName;
	cout << "Введите ваше имя на английском языке, чтобы имя пользователя сгенерировалось случайным образом:" << endl;
	getline(cin, userName);
	userNickName = genNickname(userName);
	return userNickName;
}

// Создание пароля пользователя самостоятельно
string user::createUserPasswordByYourself() {
	string userPassword;
	cout << "Создайте пароль для вашего пользователя:" << endl;
	getline(cin, userPassword);
	return userPassword;
}

// Создание пароля пользователя с помощью генерирования пароля
string user::createUserPasswordByGenerating() {
	string userPassword;
	//generationPassword::generationPassword();
	//userPassword = generationPassword::generate();
	//return userPassword;
}

void user::editUserInfo() {
	int x1;
	string  userNickname;
	string userPassword;
	cout << "Выберите, какие данные пользователя вы желаете изменить:" << endl << "1. Имя пользователя" << endl << "2. Пароль пользователя" << endl;
	cin >> x1;
	switch (x1){
	case 1:
		int x2;
		cout << "Каким способом вы желаете изменить имя пользователя?" << endl << "1. Самостоятельно" << endl << "2. С помощью генерации имени пользователя" << endl;
		cin >> x2;
		switch (x2) {
		case 1:
			userNickname = user::createUserNicknameByYourself();
			cout << "Имя пользователя успешно изменено" << endl;
			break;
		case 2:
			userNickname = user::createUserNicknameByGenerating();
			cout << "Имя пользователя успешно изменено" << endl;
			break;
		default:
			cout << "Неправильный выбор!" << endl;
			break;
		}
	case 2:
		int x2;
		cout << "Каким способом вы желаете изменить пароль?" << endl << "1. Самостоятельно" << endl << "2. С помощью генерации имени" << endl;
		cin >> x2;
		switch (x2){
		case 1:
			userPassword = user::createUserPasswordByYourself();
			cout << "Пароль успешно изменен" << endl;
			break;
		case 2:
			userPassword = user::createUserPasswordByGenerating();
			cout << "Пароль успешно изменен" << endl;
			break;
		default:
			cout << "Неправильный выбор!" << endl;
			break;
		}
	default:
		cout << "Неправильный выбор!";
		break;
	}
}

void user::displayUserInfo() {
	cout << "Имя пользователя: " << userNickname << endl;
	cout << "Пароль: " << userPassword << endl;
}

void user::displayAuthMenu() {
	string nickname, password;
	cout << "Введите имя вашего пользователя: ";
	getline(cin,nickname);
	cout << "Введите ваш пароль: ";
	getline(cin, password);

	if (nickname == userNickname && password == userPassword) {
		cout << "Вход выполнен. Добро пожаловать, " << userNickname << "!\n";
	}
	else {
		cout << "Вход не выполнен. Неверное имя или пароль!\n";
	}
}

void user::displayRegistrationMenu() {
	
}
