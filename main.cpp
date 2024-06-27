#include <iostream>
#include <string>
#include "generationNickname.h";
#include "generationPassword.h"

using namespace std;

int main()
{
    cout << genNickname("Bobryatina");

    //Генерация пароля
    generationPassword genPass;
    std::string password = genPass.generate();
    std::cout << "Generated password: " << password << std::endl;
}