#include"file.h"

void demo_perms(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
        << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
        << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
        << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
        << '\n';
}

File::File() {};
File::~File() = default;

int File::userFile() {

    std::fstream users_file = std::fstream("Users.txt", std::ios::in | std::ios::out);

    if (!users_file)
    {
        users_file = std::fstream("Users.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }

    if (!users_file.is_open())
    {
        std::cout << "\tНе удалось открыть файл Users.txt" << std::endl;
        return -1;
    }
    else
    {

        _users.emplace_back("Usr1", "1usr", "pass1");
        _users.emplace_back("Usr2", "2usr", "pass2");
        _users.emplace_back("Usr3", "3usr", "pass3");
        _users.emplace_back("Usr4", "4usr", "pass4");
        _users.emplace_back("Usr5", "5usr", "pass5");

        for (auto& user : _users)
        {
            users_file << user << std::endl;
        }

        std::cout << "\tДанные всех пользователей из текстового файла User.txt:" << std::endl;

        users_file.seekg(0, std::ios::beg);

        std::string userName, userLogin, userPass;
        std::string line;

        std::cout << std::endl;
        while (getline(users_file, line))
        {
            std::istringstream input{ line };
            getline(input, userName, ';');
            getline(input, userLogin, ';');
            getline(input, userPass);
            std::cout << "\tИмя: " << userName << "\tЛогин: " << userLogin << "\tПароль: " << userPass << std::endl;
        }
        std::cout << "\tСоздан файл с разрешениями: ";
        demo_perms(fs::status("Users.txt").permissions());
        fs::permissions("Users.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);

        std::cout << "\tПроверка текущего статуса разрешений: ";
        demo_perms(fs::status("Users.txt").permissions());
    }
    return 0;
}

int File::messageFile() {
    std::fstream messages_file = std::fstream("Messages.txt", std::ios::in | std::ios::out);
    if (!messages_file)
    {
        messages_file = std::fstream("Messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
    }
    if (!messages_file.is_open())
    {
        std::cout << "\tНе удалось открыть файл Messages.txt" << std::endl;
        return -1;
    }
    else
    {
        _messages.emplace_back("Hola!", "usr1", "usr4");
        _messages.emplace_back("Hallo!", "usr2", "usr3");
        _messages.emplace_back("Здравствуйте!", "usr3", "usr2");
        _messages.emplace_back("Hello!", "usr4", "usr5");
        _messages.emplace_back("Kon'nichiwa!", "usr5", "usr1");
        for (auto& message : _messages)
        {
            messages_file << message << std::endl;
        }
        std::cout << std::endl;
        std::cout << "\tДанные всех сообщений из текстового файла Messages.txt:" << std::endl;
        std::cout << std::endl;
        messages_file.seekg(0, std::ios::beg);
        std::string messageText, messageSender, messageReceiver;
        std::string line;

        while (getline(messages_file, line))
        {
            std::istringstream input{ line };
            getline(input, messageText, ';');
            getline(input, messageSender, ';');
            getline(input, messageReceiver);
            std::cout << "\t(oт) " << messageSender << "\t(для) " << messageReceiver << "\t(сообщение) " << messageText << std::endl;
        }
        std::cout << std::endl;
        std::cout << "\tСоздан файл с разрешениями: ";
        demo_perms(fs::status("Messages.txt").permissions());
        fs::permissions("Messages.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);

        std::cout << "\tПроверка текущего статуса разрешений: ";
        demo_perms(fs::status("Messages.txt").permissions());
    }
    return 0;
}

std::ostream& operator <<(std::ostream& os, Message& message)
{
    os << message._text;
    os << ';';
    os << message._sender;
    os << ';';
    os << message._receiver;
    return os;
}
std::ostream& operator <<(std::ostream& os, User& user)
{
    os << user._name;
    os << ';';
    os << user._login;
    os << ';';
    os << user._pass;
    return os;
}