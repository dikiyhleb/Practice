#include "user.h"
#include <fstream>
#include <Windows.h>
#include "generationNickname.h"
#include "generationPassword.h"
using namespace std;
vector<user> users;

int main() {
    setlocale(LC_ALL, "ru");
    user currentUser;
    int choice;

    while (true) {
        // Название менюшки
        cout << "1. Регистрация\n2. Авторизация\n3. Показать всех пользователей\n4. Выход\n";
        cout << "Выберите опцию: ";
        cin >> choice;
        cin.ignore(); 
        // Сделать функции класса статическими
        switch (choice) {
        case 1:
            currentUser.displayRegistrationMenu(users);
            users.push_back(currentUser);
            break;
        case 2:
            currentUser.displayAuthMenu(users);
            break;
        case 3:
            currentUser.displayUserInfo(users);
            break;
        case 4:
            return 0;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
