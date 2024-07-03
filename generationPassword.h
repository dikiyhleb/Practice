#ifndef GENERATIONPASSWORD_H
#define GENERATIONPASSWORD_H

#include <string>
#include <ctime>
#include <cstdlib>

class generationPassword
{
private:
    int length;
    std::string charset;

public:
    generationPassword()
        : charset("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~")
    {
        srand(time(0));
        length = rand() % 5 + 8; // случайная длина пароля от 8 до 12
    }

    std::string generate()
    {
        std::string password;
        for (int i = 0; i < length; ++i)
        {
            password += charset[rand() % charset.length()];
        }
        return password;
    }
};

#endif // GENERATIONPASSWORD_H
