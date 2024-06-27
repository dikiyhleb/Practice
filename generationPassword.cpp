#include "generationPassword.h"

generationPassword::generationPassword()
    : charset("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~")
{
    srand(time(0));
    length = rand() % 5 + 8; // случайная длина пароля от 8 до 12 символов
}

std::string generationPassword::generate()
{
    std::string password;
    for (int i = 0; i < length; ++i)
    {
        password += charset[rand() % charset.length()];
    }
    return password;
}