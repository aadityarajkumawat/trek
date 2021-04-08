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

bool stage_entities(int argc, char** argv) {
    if (argc == 2) {
        std::cout << "Error: trek add <filename>, <filename> is missing" << std::endl;
        return false;
    }

    if (!strcmp(argv[2], ".")) {
        const char* pwd = get_current_dir_name();

        struct dirent* entry;
        DIR* dir = opendir(pwd);

        if (dir == NULL) return false;

        while ((entry = readdir(dir)) != NULL) {
            const char* entity_name = entry->d_name;
            std::string entity_name_str = entity_name;

            char char_0 = entity_name_str[0];
            std::string char0_str(1, char_0);
            const char* first = char0_str.c_str();

            std::string s = entry->d_name;
            s = s + "\n";

            if (strcmp(first, ".")) {
                std::string pwd_str = get_current_dir_name();
                std::string ss = "test.txt";
                bool b = write_to_file(ss, s);
            }
        }
        closedir(dir);
    }

    return true;
}

bool commit_changes() {
    return false;
}

int main(int argc, char** argv) {
    if (!strcmp(argv[1], "init")) {
        initilaize_repo();
    }
    else if (!strcmp(argv[1], "add")) {
        stage_entities(argc, argv);
    }

    return EXIT_SUCCESS;
}
