#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <dirent.h>

void print_vector_int(std::vector<int>& n) {
    for (int i = 0;i < n.size();i++) {
        std::cout << n[i] << " ";
    }
}

void print_vector_string(std::vector<std::string>& n) {
    for (int i = 0;i < n.size();i++) {
        std::cout << n[i] << " ";
    }
}

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
    }
    closedir(dir);

    return file_dir_found;
}

bool find_string_in_vector(std::vector<std::string>& strings, std::string str_to_find) {
    bool b = false;
    for (std::string& str : strings) {
        if (str_to_find == str) {
            b = true;
            break;
        }
    }

    return b;
}