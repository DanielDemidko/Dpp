#include "CatTypes.h"
#include <vector>
#include <memory>
#include "CatObject.h"

const std::string CatTypes::String = typeid(std::string).name();
const std::string CatTypes::Double = typeid(double).name();
const std::string CatTypes::Int = typeid(int).name();
const std::string CatTypes::Char = typeid(char).name();
const std::string CatTypes::Bool = typeid(bool).name();
const std::string CatTypes::List = typeid(std::shared_ptr<std::vector<CatObject>>).name();
