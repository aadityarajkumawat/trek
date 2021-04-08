#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include "path.h"
#include "fs.h"
#include "utils.h"

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
