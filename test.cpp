#include <iostream>
#include <fstream>

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

    std::string s1 = "cool";
    std::string s2 = "cool";

    if (s1 == s2) {
        std::cout << "hi" << std::endl;
    }

    return 0;
}
