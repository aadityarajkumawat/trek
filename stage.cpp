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

std::vector<std::string> get_staged_files() {
    std::fstream my_file;
    std::vector<std::string> file_names;
    my_file.open("./.trek/index", std::ios::in);
    if (!my_file) {
        file_names = {};
        return file_names;
    }
    else {
        char ch;

        std::string file_name;
        while (1) {
            my_file >> ch;
            if (my_file.eof())
                break;

            if (ch != '/') {
                file_name += ch;
            }
            else {
                file_names.push_back(file_name);
                file_name = "";
            }
        }

    }
    my_file.close();

    return file_names;
}

std::vector<std::string> get_dir_files(const char* path) {
    struct dirent* entry;
    std::vector<std::string> c;
    DIR* dir = opendir(path);

    if (dir == NULL) return {};

    while ((entry = readdir(dir)) != NULL) {
        std::string cc = entry->d_name;
        c.push_back(cc);
    }
    closedir(dir);

    return c;
}

/**
 * TODO: Handle individual file staging
*/
bool stage_entities(int argc, char** argv) {
    if (argc == 2) {
        std::cout << "Error: trek add <filename>, <filename> is missing" << std::endl;
        return false;
    }

    if (!strcmp(argv[2], ".")) {
        const char* pwd = get_current_dir_name();

        struct dirent* entry;
        DIR* dir = opendir(pwd);
        DIR* d = opendir("./pages");

        if (dir == NULL) return false;

        std::vector<std::string> staged_files = get_staged_files();

        if ((entry = readdir(d)) == NULL) {
            std::cout << "Dir" << std::endl;
        }

        while ((entry = readdir(dir)) != NULL) {
            const char* entity_name = entry->d_name;
            std::string entity_name_str = entity_name;

            char char_0 = entity_name_str[0];
            std::string char0_str(1, char_0);
            const char* first = char0_str.c_str();

            std::string s = entry->d_name;
            s = s + "/\n";

            if (strcmp(first, ".")) {
                bool file_is_found = find_string_in_vector(staged_files, entity_name_str);

                if (!file_is_found) {
                    std::string ss = "./.trek/index";
                    std::string f = entity_name_str + "/\n";
                    bool written = write_to_file(ss, f);
                }
            }
        }
        closedir(dir);
    }

    return true;
}