#include <iostream>
#include <string>
#include "generationNickname.h"
#include "generationPassword.h"
#include "encryption.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    generationPassword genPass;
    int x;
    while (true) {
        cout << " РЕГИСТРАЦИЯ" << '\n';
        cout << "1 - Сгенерировать никнейм" << '\n';
        cout << "2 - Сгенерировать пароль" << '\n';
        cout << "3 - Выход" << '\n';

        cin >> x;

        switch (x) {
        case 1: {
            cout << " Вариация генераций " << '\n';
            cout << "1 вариант: " << genNicknameByBase() << '\n';
            cout << "2 вариант: " << genNicknameByBase() << '\n';
            cout << "3 вариант: " << genNicknameByBase() << '\n';
            break;
        }
        case 2: {
            cout << "Ваш пароль привязанный к аккунту запишите его на листочке: ";
            std::string password = genPass.generate();
            std::cout << password << std::endl;
            break;
        }


        case 3: {
            return 0;
        default:
            cout << "Некорректный выбор" << endl;
            break;
        }
        }

        return 0;
    }
}
