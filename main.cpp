#include <bits/stdc++.h>
#include <iostream>
#include "fs.h"
#include "path.h"
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include "utils.h"

struct commit {
    char* tree;
    char* parent;
    char* author;
    std::string message;
};

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

void list_dir(const char* path) {
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) return;

    while ((entry = readdir(dir)) != NULL) {
        std::cout << entry->d_name << std::endl;
    }
    closedir(dir);
}

bool initilaize_repo() {
    std::string pwd = get_current_dir_name();
    char* pwd_char = get_current_dir_name();

    /** check if repo is already initialized */
    if (check_file_dir(pwd_char, ".trek")) {
        std::cout << "A terk repository is already initialized here" << std::endl;
        return EXIT_SUCCESS;
    }

    /** creating the trek data store directory */
    std::string data_store = ".trek";
    std::vector<std::string> parts_of_path;
    parts_of_path.push_back(data_store);
    std::string data_store_path = join(pwd, parts_of_path);
    bool data_store_container_created = create_directory(data_store_path);
    if (!data_store_container_created) return EXIT_FAILURE;

    /** creating the .terk/object directory inside .trek to keep commits */
    std::string object_dir_name = "objects";
    parts_of_path.push_back(object_dir_name);
    std::string object_dir_path = join(pwd, parts_of_path);
    bool objects_dir_created = create_directory(object_dir_path);
    if (!objects_dir_created) return EXIT_FAILURE;

    parts_of_path.pop_back();

    /** creating the .trek/refs directory to keep track of references */
    std::string refs_dir_name = "refs";
    parts_of_path.push_back(refs_dir_name);
    std::string refs_dir_path = join(pwd, parts_of_path);
    bool refs_dir_created = create_directory(refs_dir_path);
    if (!refs_dir_created) return EXIT_FAILURE;

    /** creating a .trek/refs/REFS file in .trek/refs */
    std::string refs_filename = "REFS";
    parts_of_path.push_back(refs_filename);
    std::string refs_file_path = join(pwd, parts_of_path);
    bool refs_file_created = create_file(refs_file_path);
    if (!refs_file_created) return EXIT_FAILURE;

    parts_of_path.pop_back();
    parts_of_path.pop_back();

    /** creating a .trek/refs/index file in .trek/index */
    std::string index_filename = "index";
    parts_of_path.push_back(index_filename);
    std::string index_file_path = join(pwd, parts_of_path);
    bool index_file_created = create_file(index_file_path);
    if (!index_file_created) return EXIT_FAILURE;

    std::cout << "Initiliazed a trek repository in " << get_current_dir_name() << std::endl;

    return EXIT_SUCCESS;
}

bool write_to_file(std::string& file_name, std::string& content) {
    std::fstream file;
    file.open(file_name, std::ios::app);

    if (!file) {
        return false;
    }
    else {
        file << content;
        file.close();
        return false;
    }
}

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
            // std::cout << entry->d_name << "->" << entry->d_name[0] << std::endl;
            const char* entity_name = entry->d_name;
            // const char* e = entity_nam;

            // std::cout << e << std::endl;

            std::string s = entry->d_name;
            s = s + "\n";

            // if (strcmp(e, ".")) {
            //     std::string pwd_str = get_current_dir_name();
            //     std::string ss = "test.txt";
            //     bool b = write_to_file(ss, s);
            // }
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

    // std::string n = "test.txt";
    // std::string cont = "\ncool";
    // bool f = write_to_file(n, cont);

    // std::string pwd = get_current_dir_name();
    // std::cout << pwd.append("/.trek/refs/REFS") << std::endl;
    // bool c = create_file(pwd.append("/.trek/refs/REFS"));

    return EXIT_SUCCESS;
}
