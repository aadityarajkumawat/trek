#include <bits/stdc++.h>

#ifndef PATH_H
#define PATH_H

/**
 * Takes two parameters first is a string which is base of the path
 * and second is a vector of strings, it combines the base path with
 * all the parts provided in the vector.
*/
std::string join(std::string& base_path, std::vector<std::string>& parts_of_path);


/**
 * Takes first argument as a string and second as a string strictly
 * of type, left_trim, right_trim, trim and trims all slashes from
 * provided side.
*/
std::string trim_slash(std::string& path, std::string& trim_type);

#endif 
