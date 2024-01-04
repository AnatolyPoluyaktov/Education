/**
 * @mainpage
 * Проект с реализацией сортировок:
 * выбором, простыми вставками и быстрой, а также
 * замером времени их работы.
 * Данные для сортировки содержатся в csv-файле,
 * сгенерированном вне данного проекта .
 * Время работы каждой сортировки на данных каждого объема
 * записывается в файл times.csv.
 */
#include <iostream>
#include "passanger.hpp"

#include "sort.hpp"
#include <iomanip>
#include <chrono>
#include <string>

int main() {

    std::string path = "D:\\my_folder\\jupyter\\laba1\\";
    std::vector<std::string> siz = {"100", "500", "1000", "10000", "15000", "20000", "30000", "50000", "70000",
                                    "100000"};
    // getline(std::cin , size);
    std::fstream tim("time.csv", std::ios::app);
    tim << "choice  " << "insertion " << "qick" << std::endl;
    for (auto size:siz) {
        std::string filename = path + "dataset" + size + ".csv";
        //std::cout<<filename;
        std::ifstream input(filename);
        std::string line;
        std::vector<Psg::Passenger> passengers_for_choice;
        std::vector<Psg::Passenger> passengers_for_insertion;
        std::vector<Psg::Passenger> passengers_for_qick;
        if (input.is_open()) {
            while (getline(input, line)) {
                try {
                    passengers_for_choice.push_back(Psg::parse(line));
                    passengers_for_insertion.push_back(Psg::parse(line));
                    passengers_for_qick.push_back(Psg::parse(line));
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

        tim << size << ",";
        auto t1 = std::chrono::high_resolution_clock::now();

        algo::choice_sort(passengers_for_choice);

        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        tim << duration << ",";

        t1 = std::chrono::high_resolution_clock::now();
        algo::insertion_sort(passengers_for_insertion);
        t2 = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        tim << duration << ",";

        t1 = std::chrono::high_resolution_clock::now();
        algo::qick_sort(passengers_for_qick, 0, passengers_for_qick.size() - 1);
        t2 = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        tim << duration << std::endl;
        std::string path1 = "D:\\my_folder\\jupyter\\laba1\\sorted_mass\\";

        //std::string fileoutput=path1+"SortedDataSet"+size+;
        //std::cout<<fileoutput;

        std::ofstream output(path1 + "ChoiceSortedDataSet" + size + ".csv");
        for (auto a: passengers_for_choice) {
            output << a << std::endl;
        }
        output.close();

        std::ofstream output1(path1 + "InsertionSortedDataSet" + size + ".csv");
        for (auto a: passengers_for_insertion) {
            output1 << a << std::endl;
        }
        output1.close();

        std::ofstream output2(path1 + "QickSortedDataSet" + size + ".csv");
        for (auto a: passengers_for_qick) {
            output2 << a << std::endl;
        }
        output2.close();

    }


    return 0;
}
