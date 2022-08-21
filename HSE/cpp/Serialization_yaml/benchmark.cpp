#include <benchmark/benchmark.h>
#include "serialization_deserialization.hpp"
#include<iostream>

static void BM_TEST_YAMLCPP_DESERIALIZATION(benchmark::State &state)
{
    int i  = state.range(0);
    std::string filename = "yaml_test" + std::to_string(i) +
            "x" + std::to_string(i) +".yaml";
    for(auto _ : state)
    {
        serial::deserialization(filename);
    }

}
static void BM_TEST_YAMLCPP_SERIALIZATION(benchmark::State &state)
{
    int i = state.range(0);
    std::string filename = "yaml_test" + std::to_string(i) +
            "x" + std::to_string(i) +".yaml";
    YAML::Node doc = serial::deserialization(filename);
    for(auto _ : state)
    {
        serial::serialization(doc,filename,state);
    }
}

static void BM_TEST_LIBFYAML_DESERIALIZATION(benchmark::State &state)
{
    int i = state.range(0);
        std::string filename = "yaml_test" + std::to_string(i) +
                "x" + std::to_string(i) +".yaml";
        for (auto _ : state) {
            struct fy_document* document = serial::fy_deserialization(filename.c_str());
            fy_document_destroy(document);
        }

}

static void BM_TEST_LIBFYAML_SERIALIZATION(benchmark::State &state)
{
    int i = state.range(0);
    std::string filename = "yaml_test" + std::to_string(i) +
            "x" + std::to_string(i) +".yaml";
    struct fy_document* document = serial::fy_deserialization(filename.c_str());
     std::string u = "./output/yaml_test" + std::to_string(i) +
             "x" + std::to_string(i) +".yaml";

    for(auto _ : state)
    {
        serial::fy_serialization(document,u.c_str(),state);


    }
   fy_document_destroy(document);
}

static void BM_TEST_LIBYAML_DESERIALIZATION(benchmark::State &state)
{
    int i  = state.range(0);

    std::string filename = "yaml_test" + std::to_string(i) +
            "x" + std::to_string(i) +".yaml";

    for(auto _ : state)
    {
        yaml_document_t doc  = serial::libyaml_deserialization(filename,state);
        yaml_document_delete(&doc);
    }

}

static void BM_TEST_LIBYAML_SERIALIZATION(benchmark::State &state)
{

    int i = state.range(0);
    std::string filename = "yaml_test" + std::to_string(i) +
            "x" + std::to_string(i) +".yaml";
    for(auto _ : state)
    {   state.PauseTiming();
        yaml_document_t document = serial::libyaml_deserialization(filename,state);
         std::string u = "./output/"+filename;
         state.ResumeTiming();
        serial::libyaml_serialization(&document,u,state);
        state.PauseTiming();
        yaml_document_delete(&document);
        state.ResumeTiming();
    }




}



BENCHMARK(BM_TEST_YAMLCPP_DESERIALIZATION)->DenseRange(10,290,10);
BENCHMARK(BM_TEST_YAMLCPP_SERIALIZATION)->DenseRange(10,290,10);
BENCHMARK(BM_TEST_LIBFYAML_DESERIALIZATION)->DenseRange(10,290,10);
BENCHMARK(BM_TEST_LIBFYAML_SERIALIZATION)->DenseRange(10,290,10);
BENCHMARK(BM_TEST_LIBYAML_DESERIALIZATION)->DenseRange(10,290,10);
BENCHMARK(BM_TEST_LIBYAML_SERIALIZATION)->DenseRange(10,290,10);
BENCHMARK_MAIN();
