#include"document_generator.hpp"
namespace gen{
std::string gen_random_str() {

    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> uniform_dist(1, 1000);
        std::shuffle(str.begin(), str.end(), generator);
       int len = uniform_dist(generator);
        return str.substr(1, len);

    }


 void gen_yaml_file(int len)
 {
    YAML::Node doc;
    std::string head;
    for(int i = 0; i < len; ++i)
    {
        head = gen_random_str();
        for(int j =0; j < len; ++j)
        {
            doc[head].push_back(gen_random_str());
        }
    }
    std::string file_name = "yaml_test" + std::to_string(len) +
            "x" + std::to_string(len) +".yaml";
    std::ofstream fout(file_name);
    fout << doc;

}

}


