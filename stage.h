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

#ifndef STAGE_H
#define STAGE_H

std::vector<std::string> get_staged_files();

std::vector<std::string> get_dir_files(const char* path);

bool stage_entities(int argc, char** argv);

#endif /* STAGE_H */
