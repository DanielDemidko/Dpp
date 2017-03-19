#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <functional>
#include <memory>

#include "Program.h"


int main(const int argc, const char *const *const argv)
{
    std::vector<std::string> args;
    std::copy(argv, argv + argc, std::back_inserter(args));
    Program("Test.dpp").Run(args);
}