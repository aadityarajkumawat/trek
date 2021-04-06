#include <iostream>
#include <vector>
#include <string>

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