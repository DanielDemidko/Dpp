#include "Module.h"
#include "Code.h"

Module::Module(const std::string &path) : File(Code::ReadFile(path)) {}
