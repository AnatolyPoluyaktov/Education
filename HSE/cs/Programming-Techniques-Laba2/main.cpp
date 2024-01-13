
// объект пассажир(ФИО ,номер каюты, тип каюты,порт назначения)
#include <iostream>
#include "passanger.hpp"
///#include <time.h>
#include <iomanip>
#include <chrono>
#include <string>
#include "search.hpp"
#include "sort.hpp"



int main() {
    std::string path="D:\\my_folder\\jupyter\\laba2\\";
    std::vector<std::string> siz ={"100","500","1000","10000","15000","20000","30000","50000","70000","100000"};
    //std::ifstream input(path+"test.csv");
    std::ofstream tim("time.csv", std::ios::app);
    tim <<"size," <<"line,"<<"binar_sorted,"<<"binar_unsorted"<<std::endl;
    std::string line;
    for(auto size:siz) {
        std::string filename =path+"Unsorted_datasets\\"+"dataset"+size+".csv";
        std::string line;
        std::ifstream input(filename);
        std::vector<Psg::Passenger> passengers;
        if (input.is_open()) {
            while (getline(input, line)) {
                try {
                    passengers.push_back(Psg::parse(line));
                }
                catch (std::logic_error &le) {
                    std::cout << le.what();
                    return 3;
                }
            }
        } else if (!input.is_open()) {
            std::cerr << "not open!";
            return 1;
        } else if (input.peek() == EOF) {
            std::cerr << "Fail empty\n";
            return 2;
        }
        input.close();

    tim<<size<<",";
        auto t1 = std::chrono::high_resolution_clock::now();
        std::vector<Psg::Passenger>ans=srh::linear(passengers,"Jeddah");
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        tim << duration << ",";

    std::ofstream output1(path + "found\\"+"linear"+size + ".csv");
    for (auto a: ans) {
        output1 << a << std::endl;
    }

    t1 = std::chrono::high_resolution_clock::now();
    algo::qick_sort(passengers,0,passengers.size()-1);

    std::pair<int,int> ans2=srh::binary(passengers,"Jeddah");
        t2 = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        tim << duration << ",";

    std::ofstream output2(path +  "found\\"+"binary_sorted"+size + ".csv");
    for (int i =ans2.first; i <ans2.second;++i) {
        output2 << passengers[i] << std::endl;
    }
        t1 = std::chrono::high_resolution_clock::now();

        std::pair<int,int> ans3=srh::binary(passengers,"Jeddah");
        t2 = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        tim << duration << ",";

        std::ofstream output3(path +  "found\\"+"binary_unsorted"+size + ".csv");
        for (int i =ans3.first; i <ans2.second;++i) {
            output3 << passengers[i] << std::endl;
        }

        std::multimap<std::string, Psg::Passenger> mp = srh::formed_multimap(passengers);
        std::pair<std::multimap<std::string, Psg::Passenger>::iterator,
                std::multimap<std::string, Psg::Passenger>::iterator> ret;
        t1 = std::chrono::high_resolution_clock::now();
        ret = mp.equal_range("Jeddah");
        t2 = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
        tim << duration << std::endl;

        std::ofstream output4(path +"found\\" "multimap" +size+ ".csv");
        for (std::multimap<std::string, Psg::Passenger>::iterator it = ret.first; it != ret.second; ++it) {
            output4 << it->second << std::endl;
        }
  }



    return 0;
}
