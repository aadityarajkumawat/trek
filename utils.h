#include <iostream>
#include <vector>
#include <string>

#ifndef UTILS_H
#define UTILS_H

void print_vector_int(std::vector<int>& n);
void print_vector_string(std::vector<std::string>& n);

bool find_string_in_vector(std::vector<std::string>& strings, std::string str_to_find);

bool check_file_dir(const char* path, const char* file_dir_name);

#endif