#include <bits/stdc++.h>
#include <iostream>
#include "fs.h"
#include "path.h"
#include <unistd.h>
#include <stdio.h>
#include <filesystem>
#include <dirent.h>
#include <sys/types.h>

bool check_file_dir(const char* path, const char* file_dir_name) {
    bool file_dir_found = false;
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) return false;

    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, file_dir_name)) {
            file_dir_found = true;
            break;
        }
        // std::cout << entry->d_name << std::endl;
    }
    closedir(dir);

    return file_dir_found;
}

void list_dir(const char* path) {
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) return;

    while ((entry = readdir(dir)) != NULL) {
        std::cout << entry->d_name << std::endl;
    }
    closedir(dir);
}

bool initilaize_repo(const char* argv1) {
    if (!strcmp(argv1, "init")) {
        std::string pwd = get_current_dir_name();
        char* pwd_char = get_current_dir_name();

        /** check if repo is already initialized */
        if (check_file_dir(pwd_char, ".trek")) {
            std::cout << "A repository is already initialized here" << std::endl;
            return true;
        }
        std::string data_store = ".trek";
        std::vector<std::string> parts_of_path;

        parts_of_path.push_back(data_store);

        std::string data_store_path = join(pwd, parts_of_path);

        bool data_store_container_created = create_directory(data_store_path);
        if (!data_store_container_created) return EXIT_FAILURE;

        std::cout << "Initiliazed a pit repository in " << get_current_dir_name() << std::endl;
    }

    return EXIT_SUCCESS;
}

int main(int argc, char** argv) {
    initilaize_repo(argv[1]);

    // list_dir(get_current_dir_name());

    return EXIT_SUCCESS;
}
