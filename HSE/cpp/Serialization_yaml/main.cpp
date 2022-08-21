//#include "yaml-cpp/yaml.h"
//#include <iostream>
//#include "libfyaml.h"
//#include "yaml.h"
//#include <fstream>
//#include <benchmark/benchmark.h>

//#include "document_generator.hpp"
//#include "libfyaml/config.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include <assert.h>
/*#include "serialization_deserialization.hpp*/"
//static void BM_StringCreation(benchmark::State& state) {
//  for (auto _ : state)
//    std::string empty_string;
//}
// Register the function as a benchmark
//BENCHMARK(BM_StringCreation);
//BENCHMARK_MAIN();


//int main()
//{

//   yaml_parser_t parser;
//   yaml_event_t event;
//   yaml_parser_initialize(&parser);

//   YAML::Emitter out;
// /*  //out << "Hello, World!";
//   for (int i = 10; i < 300; i+=10)
//       {
//           std::string filename = "yaml_test" + std::to_string(i) +
//                   "x" + std::to_string(i) +".yaml";

//           yaml_document_t document = serial::libyaml_deserialization(filename);
//            filename = "./output/"+filename;
//            serial::libyaml_serialization(&document,filename);
      // }
//   std::cout << "Here's the output YAML:\n" << out.c_str(); // prints "Hello, World!"
//   printf("%s\n", fy_library_version());

//   YAML::Node doc =YAML::LoadFile("test.yaml");
 //  yaml_document_t kek;
   // kek = serial::libyaml_deserialization("yaml_test290x290.yaml");
    //serial::libyaml_serialization(&kek,"lol.yaml");
//    YAML::Node doc;
//    doc = serial::deserialization("libyaml_test_500x500.yaml");
//    serial::serialization(doc,"kek.yaml");
//    struct fy_document* doc2;
//    doc2 = serial::fy_deserialization("libyaml_test_30x30.yaml");
//    serial::fy_serialization(doc2,"aaaaa.yaml");
//    std::cout<<gen::gen_random_str();
//    std::cout << gen::gen_random_str(gen::get_random_number());
//   return 0;
//}
