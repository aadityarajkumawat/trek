#include <iostream>

int main() {
    /**
     * Normal charcter behaviour
    char a = 'f';
    char* address_of_char_a = &a;
    std::cout << a << std::endl;
    std::cout << *address_of_char_a << std::endl;
    */

    const char* a = "col";
    // const char* a0 = (char*)a[0];
    // std::cout << a0 << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a[2] << std::endl;

    return 0;
}
