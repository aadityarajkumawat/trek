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
#include "stage.h"

bool commit_changes(int argc, char** argv) {
    return false;
}

int main(int argc, char** argv) {
    if (!strcmp(argv[1], "init")) {
        initilaize_repo();
    }
    else if (!strcmp(argv[1], "add")) {
        stage_entities(argc, argv);
    }
    else if (!strcmp(argv[1], "commit")) {
        commit_changes(argc, argv);
    }

    // std::vector<std::string> file_names = get_staged_files();

    // for (std::string& d : file_names) {
    //     std::cout << "cool" << std::endl;
    //     std::cout << d << std::endl;
    // }

    return EXIT_SUCCESS;
}
