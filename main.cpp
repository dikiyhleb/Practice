#include "user.h"
#include <iostream>
#include <locale>
#include <Windows.h>
using namespace std;

vector<user> users;

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    user currentUser;
    int choice;

    while (true) {
        cout << "......Учетная запись.......\n";
        cout << "1. Регистрация\n2. Авторизация\n3. Показать всех пользователей\n4. Выход\n";
        cout << "Выберите опцию: ";
        cin >> choice;
        cin.ignore();

        currentUser.handleUserChoice(choice, users);
    }

    return 0;
}
