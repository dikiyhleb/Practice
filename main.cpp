#include "user.h"
#include <iostream>
#include <locale>
#include <Windows.h>
using namespace std;

vector<user> users;

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    user currentUser;
    int choice;

    while (true) {
        cout << "������� ������\n";
        cout << "1. �����������\n2. �����������\n3. �������� ���� �������������\n4. �����\n";
        cout << "�������� �����: ";
        cin >> choice;
        cin.ignore();

        currentUser.handleUserChoice(choice, users);
    }

    return 0;
}
