#include "user.h"
#include "generationNickname.h"
#include "generationPassword.h"
using namespace std;

user::user() {}

user::user(const string& userNickname, const string& userPassword) {
    this->userNickname = userNickname;
    this->userPassword = userPassword;
}

string user::createUserNicknameByYourself() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string userNickname;
    cout << "������� ��� ������������ �� ���������� �����: ";
    cin >> userNickname;
    cout << endl;
    if (userNickname.empty()) {
        cout << "��� ������������ �� ����� ���� ������!" << endl;
        return "";
    }
    return userNickname;
}

string user::createUserNicknameByGenerating() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string userNickname;
    cout << "�������� ���������:\n";
    string nick1 = genNicknameByBase();
    string nick2 = genNicknameByBase();
    string nick3 = genNicknameByBase();
    cout << "1. " << nick1 << '\n';
    cout << "2. " << nick2 << '\n';
    cout << "3. " << nick3 << '\n';
    int choice;
    cout << "�������� ����� �������� ����� ������������ (1-3): ";
    cin >> choice;
    switch (choice) {
    case 1:
        userNickname = nick1;
        break;
    case 2:
        userNickname = nick2;
        break;
    case 3:
        userNickname = nick3  ;
        break;
    default:
        cout << "�������� �����. ��� ������������ �� �������." << endl;
        break;
    }
    cout << "��� ������������ ������!\n" << endl;
    return userNickname;
}

string user::createUserPasswordByYourself() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string userPassword;
    cout << "���������� ������: ";
    cin >> userPassword;
    cout << "������ �����!\n" << endl;
    return userPassword;
}

string user::createUserPasswordByGenerating() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    generationPassword genPass;
    string userPassword = genPass.generate();
    cout << "������ ������! ��� ������: " << userPassword << endl;
    return userPassword;
}

void user::displayUserInfo(vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    for (const user& User : users) {
        cout << "��� ������������: " << User.userNickname << endl;
        // ���� ����� ���������� ������:
        // cout << "������: " << User.userPassword << endl;
    }
}

void user::displayAuthMenu(vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    string nickname, password;
    cout << "������� ��� ������ ������������: ";
    cin >> nickname;

    bool userFound = false;

    for (const auto& User : users) {
        if (User.userNickname == nickname) {
            userFound = true;
            cout << "������� ��� ������: ";
            cin >> password;

            if (User.userPassword == password) {
                cout << "���� ��������. ����� ����������, " << User.userNickname << "!\n";
            }
            else {
                cout << "���� �� ��������. �������� ��� ��� ������!\n";
            }
            break;
        }
    }

    if (!userFound) {
        cout << "������������ � ����� ������ �� ������! " << endl;
    }
}

void user::displayRegistrationMenu(vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    cout << "\n..........���� �������� ������������..........\n";
    cout << "�������� �������� ����� ������������:\n1. ��������������\n2. � ������� ��������� ����\n3. �����\n";
    int choice;
    cout << "�������� ������� ��� �������: ";
    cin >> choice;
    string userNickname, userPassword;
    switch (choice) {
    case 1:
        userNickname = createUserNicknameByYourself();
        break;
    case 2:
        userNickname = createUserNicknameByGenerating();
        break;
    case 3:
        return;
    default:
        cout << "�������� �����!\n";
        return;
    }

    cout << "�������� ������\n";
    cout << "�������� �������� ������:\n1. ��������������\n2. � ������� ��������� ������\n";
    int choice1;
    cout << "�������� ������� ��� �������: ";
    cin >> choice1;
    switch (choice1) {
    case 1:
        userPassword = createUserPasswordByYourself();
        break;
    case 2:
        userPassword = createUserPasswordByGenerating();
        break;
    default:
        cout << "�������� �����!\n";
        return;
    }

    users.push_back(user(userNickname, userPassword));
    cout << "������� ������� ������!\n" << endl;
}

void user::handleUserChoice(int choice, vector<user>& users) {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    switch (choice) {
    case 1:
        displayRegistrationMenu(users);
        break;
    case 2:
        displayAuthMenu(users);
        break;
    case 3:
        displayUserInfo(users);
        break;
    case 4:
        cout << "����� �� ���������.\n";
        exit(0); // ���������� ���������
    default:
        cout << "�������� �����. ����������, �������� �����.\n";
        break;
    }
}
