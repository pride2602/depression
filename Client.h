#pragma
#include <fstream>
#include<iostream>
#include "User.h"
using namespace std;

void register_1()
{
    string login_new, password_new;
    cout << "Введите логин нового пользователя: " << endl;
    cin >> login_new;
    cout << "Введите пароль нового пользователя: " << endl;
    cin >> password_new;
    ofstream fout("users.txt", ios::app);
    fout << login_new << "" << password_new << endl;
    cout << "Поздравляем! Регистрация прошла успешно! " << endl;
};

void read(string login_new, string password_new)
{
    ifstream fin("users.txt");
    for (int i = 0; i < 100; i++)
    {
        fin >> user_id.login_new >> user_id.password_new;
    }
};

void login()
{
    string login_new, password_new;
    cout << "Введите логин: " << endl;
    cin >> login_new;
    cout << "Введите пароль: " << endl;
    cin >> password_new;
    read(login_new, password_new);
    for (int i = 0; i < 100; i++)
    {
        if (login_new == user_id.login_new && password_new == user_id.password_new)
        {
            cout << "Вход успешен!" << endl;
        }
    }
};