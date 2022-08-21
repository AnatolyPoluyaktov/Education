#ifndef SERIALIZATION_DESERIALIZATION_HPP
#define SERIALIZATION_DESERIALIZATION_HPP
#include "libfyaml.h"
#include "yaml-cpp/yaml.h"
#include <benchmark/benchmark.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include "yaml.h"
namespace serial {

void serialization(YAML::Node &document,const std::string filename,benchmark::State &state);
YAML::Node deserialization(const std::string filename);

void fy_serialization(struct fy_document *document, const char *filename, benchmark::State &state);
struct fy_document* fy_deserialization(const char *filename);

void libyaml_serialization(yaml_document_t* document,  std::string filename,benchmark::State &state);
yaml_document_t libyaml_deserialization(const std::string filename,benchmark::State &state);
}
#endif // SERIALIZATION_DESERIALIZATION_HPP
