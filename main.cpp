#include "user.h"
#include <fstream>
#include "generationNickname.h"
#include "generationPassword.h"
using namespace std;
vector<user> users;

int main() {
    user currentUser;
    int choice;

    while (true) {
        cout << "1. Регистрация\n2. Авторизация\n3. Показать всех пользователей\n4. Выход\n";
        cout << "Выберите опцию: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            currentUser.displayRegistrationMenu();
            break;
        case 2:
            currentUser.displayAuthMenu();
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
