#include "generationNickname.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

std::string genNicknameByBase() {
    std::ifstream file("nicknameBase.txt");
    std::string line;
    std::vector<std::string> lines;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        if (!lines.empty()) {
            static bool initialized = false;
            if (!initialized) {
                std::srand(static_cast<unsigned>(std::time(0)));
                initialized = true;
            }
            int randomIndex = std::rand() % lines.size();
            return lines[randomIndex] + randInt(0, 999);
        }
        else {
            return "File is empty.";
        }
    }
    else {
        return "Unable to open file.";
    }

    return "GeneratedNickname"; // Default return value, although ideally not reached.
}

std::string randInt(int start, int end)
{
    int randomInt = rand() % (end - start + 1) + start;
    std::string result = std::to_string(randomInt);
    return result;
}
