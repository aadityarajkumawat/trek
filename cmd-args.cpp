#include <iostream>

int main(int argc, char** argv) {
    for (int i = 0;i < argc;i++) {
        // std::cout << argv[i] << std::endl;
    }
    // void list_dir(const char* path) {
    //     struct dirent* entry;
    //     DIR* dir = opendir(path);

    //     if (dir == NULL) return;

    //     while ((entry = readdir(dir)) != NULL) {
    //         std::cout << entry->d_name << std::endl;
    //     }
    //     closedir(dir);
    // }

    return 0;
}
