#include"file.h"
#include <filesystem>

int main() {
    setlocale(0, "");
    File file;
    file.userFile();
    std::cout << std::endl;
    file.messageFile();
    return 0;
}