#include "fs.h"
#include <iostream>
#include <string>

bool create_directory(std::string& path) {
    const char* type_safe_path = path.c_str();
    if (mkdir(type_safe_path, 0777) == -1) {
        return false;
    }
    return true;
}

void create_file(std::string& file_name) {
    std::fstream file;
    file.open(file_name, std::ios::out);

    if (!file) {
        std::cout << "Error in creating file!!" << std::endl;
        return;
    }

    std::cout << "File created successfully" << std::endl;
    file.close();
    return;
}
