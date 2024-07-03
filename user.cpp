#include "user.h"
#include "generationNickname.h"
#include "generationPassword.h"
using namespace std;

user::user() {}

user::user(const string& userNickname, const string& userPassword) {
    this->userNickname = userNickname;
    this->userPassword = userPassword;
}

string user::createUserNicknameByYourself() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string userNickname;
    cout << "Введите имя пользователя на английском языке: ";
    cin >> userNickname;
    cout << endl;
    if (userNickname.empty()) {
        cout << "Имя пользователя не может быть пустым!" << endl;
        return "";
    }
    return userNickname;
}

string user::createUserNicknameByGenerating() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string userNickname;
    cout << "Варианты имени:" << endl;
    string nick1 = genNicknameByBase();
    string nick2 = genNicknameByBase();
    string nick3 = genNicknameByBase();
    cout << "1. " << nick1 << endl;
    cout << "2. " << nick2 << endl;
    cout << "3. " << nick3 << endl;
    int choice;
    cout << "Выберите номер варианта имени пользователя (1-3): ";
    cin >> choice;
    switch (choice) {
    case 1:
        userNickname = nick1;
        break;
    case 2:
        userNickname = nick2;
        break;
    case 3:
        userNickname = nick3;
        break;
    default:
        cout << "Неверный выбор." << endl;
        break;
    }
    return userNickname;
}

string user::createUserPasswordByYourself() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string userPassword;
    cout << "Придумайте пароль: ";
    cin >> userPassword;
    return userPassword;
}

string user::createUserPasswordByGenerating() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    generationPassword genPass;
    string userPassword = genPass.generate();
    cout << "Пароль: " << userPassword << endl;
    return userPassword;
}

void user::displayUserInfo(vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    cout << "\nСписок пользователей:" << endl;
    for (const user& User : users) {
        cout << "Имя пользователя: " << User.userNickname << endl;
    }
    cout << endl;
}

void user::displayAuthMenu(vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string nickname, password;
    cout << "\n..........Меню авторизации.........." << endl;
    cout << "Имя пользователя: ";
    cin >> nickname;

    bool userFound = false;

    for (const auto& User : users) {
        if (User.userNickname == nickname) {
            userFound = true;
            cout << "Пароль: ";
            cin >> password;

            if (User.userPassword == password) {
                cout << "Вход выполнен. Добро пожаловать, " << User.userNickname << "!\n" << endl;;
            }
            else {
                cout << "Вход не выполнен. Неверное имя или пароль!\n" << endl;;
            }
            break;
        }
    }

    if (!userFound) {
        cout << "Пользователь с таким именем не найден! " << endl;
    }
}

void user::displayRegistrationMenu(vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    cout << "\n..........Меню регистрации.........." << endl;
    cout << "Варианты создания имени пользователя:\n1. Самостоятельно\n2. С помощью генерации имен\n3. Выход в меню" << endl;
    int choice;
    cout << "Выберите удобный вам вариант: ";
    cin >> choice;
    string userNickname, userPassword;
    switch (choice) {
    case 1:
        userNickname = createUserNicknameByYourself();
        break;
    case 2:
        userNickname = createUserNicknameByGenerating();
        break;
    case 3:
        return;
    default:
        cout << "Неверный выбор!" << endl;
        return;
    }

    cout << "Варианты создания пароля:\n1. Самостоятельно\n2. С помощью генерации пароля" << endl;
    int choice1;
    cout << "Выберите удобный вам вариант: ";
    cin >> choice1;
    switch (choice1) {
    case 1:
        userPassword = createUserPasswordByYourself();
        break;
    case 2:
        userPassword = createUserPasswordByGenerating();
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return;
    }

    users.push_back(user(userNickname, userPassword));
    cout << "Аккаунт успешно создан!\n" << endl;
}

void user::handleUserChoice(int choice, vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    switch (choice) {
    case 1:
        displayRegistrationMenu(users);
        break;
    case 2:
        displayAuthMenu(users);
        break;
    case 3:
        displayUserInfo(users);
        break;
    case 4:
        cout << "Выход из программы." << endl;
        exit(0);
    default:
        cout << "Неверный выбор. Пожалуйста, выберите снова." << endl;
        break;
    }
}
