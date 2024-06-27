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
    generationPassword();
    std::string generate();
};

#endif // GENERATIONPASSWORD_H