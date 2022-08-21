#ifndef DOCUMENT_GENERATOR_HPP
#define DOCUMENT_GENERATOR_HPP
#include<cstdint>
#include<string>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <random>
namespace gen
{
 std::string gen_random_str();

 void gen_yaml_file(int len, int dep);
}
#endif // DOCUMENT_GENERATOR_HPP
