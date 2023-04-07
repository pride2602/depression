#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<filesystem>
#include <sstream>
#include"user.h"
#include"message.h"

namespace fs= std::filesystem;

void demo_perms(fs::perms p);


class File {
    std::vector<User> _users;
    std::vector<Message> _messages;

public:
    File();
    ~File();
    int userFile();
    int messageFile();
};