#include <bits/stdc++.h>
#include <iostream>
#include "fs.h"
#include "path.h"
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include "utils.h"
#include "init.h"

int main() {
    /**
     * Normal charcter behaviour
    char a = 'f';
    char* address_of_char_a = &a;
    std::cout << a << std::endl;
    std::cout << *address_of_char_a << std::endl;
    */

    // const char* a = "col";
    // const char* a0 = (char*)a[0];
    // std::cout << a0 << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a[2] << std::endl;

    // std::fstream my_file;
    // my_file.open("test.txt", std::ios::in);
    // if (!my_file) {
    //     std::cout << "No such file";
    // }
    // else {
    //     char ch;

    //     std::string file_name;
    //     while (1) {
    //         my_file >> ch;
    //         if (my_file.eof())
    //             break;

    //         if (ch != '/') {
    //             file_name += ch;
    //         }
    //         else {
    //             std::cout << file_name << std::endl;
    //             file_name = "";
    //         }

    //         // std::cout << ch;
    //     }

    // }
    // my_file.close();

    // std::string s1 = "cool";
    // std::string s2 = "cool";

    // if (s1 == s2) {
    //     std::cout << "hi" << std::endl;
    // }

    struct dirent* entry;
    bool is_dir = false;
    DIR* dir = opendir("./pages/Home.js");

    if (dir == NULL) {
        is_dir = false;
    }
    else {
        is_dir = true;
    }

    if (is_dir) {
        std::cout << "dir" << std::endl;
    }
    else {
        std::cout << "file" << std::endl;
    }

    return 0;
}
