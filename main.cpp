#include <bits/stdc++.h>
#include <iostream>
#include "fs.h"
#include "path.h"
#include <unistd.h>
#include <stdio.h>

void initilaize_repo(const char* argv1) {
    if (!strcmp(argv1, "init")) {
        std::string pwd = get_current_dir_name();
        std::string data_store = ".trek";
        std::vector<std::string> parts_of_path;

        parts_of_path.push_back(data_store);

        std::string data_store_path = join(pwd, parts_of_path);
        std::cout << data_store_path << std::endl;

        bool data_store_container_created = create_directory(data_store_path);

        std::cout << "Initiliazed a pit repository in " << get_current_dir_name() << std::endl;
    }
}

int main(int argc, char** argv) {
    initilaize_repo(argv[1]);

    return 0;
}
