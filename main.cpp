#include <iostream>
#include <string>
#include "generationNickname.h"
#include "generationPassword.h"
#include "encryption.h"
using namespace std;

int main()
{
    cout << genNicknameByBase() << endl;

    //Генерация пароля
    //generationPassword genPass;                                       //
    //std::string password = genPass.generate();                        //Не компилируется
    //std::cout << "Generated password: " << password << std::endl;     //

    //Проверка шифровки и дешифровки
    cout << "Enter test password: " << endl;
    string testPassword;
    cin >> testPassword;
    cout << "test password before encryption: " << testPassword << endl;
    cout << "test password after encryption: " << encrypt(testPassword) << endl;
    cout << "test password after decryption: " << decrypt(encrypt(testPassword)) << endl;
}
