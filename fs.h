#include <iostream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifndef FS_H
#define FS_H

/**
 * Takes path as a parameter and creates a folder at given location
 * if not already present.
*/
bool create_directory(std::string& path);

/**
 * Takes file name as parameter and creates a file in present
 * working directory.
*/
bool create_file(std::string& file_name);

#endif /* FS_H */
