
/**
  * @file
  * @brief Заголовочный файл, содержащий класс Passenger ,парсер строк,все перегрузки вне класса.
  */
#ifndef SORTING_PASSANGER_HPP
#define SORTING_PASSANGER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
/**
 * @namespace Psg
 * @brief Пространство имен, содержащее  класс,парсер,все перегрузки вне класса
 */
namespace Psg {
/**
 * @class Passenger
 * @brief Класс для описания пассажиров теплохода
 */
    class Passenger {

    public:
        ///конструктор по умолчанию
        Passenger() {
            Surname = "Miller";
            Name = "Peter";
            second_name = "Richard";
            cabin_number = 100;
            cabin_type = 0;
            port = "Santiago";
        }
        ///конструктор копирования
        Passenger(std::string init_Surname, std::string init_Name,
                  std::string init_second_name, int init_cabin_number, int init_cabin_type,
                  std::string init_port) {
            if (!right_str(init_Name)) {
                throw std::logic_error("Name is invalid: " + init_Name);
            }

            if (!right_str(init_Surname)) {
                throw std::logic_error("Surname is invalid: " + init_Surname);
            }

            if (!right_str(init_second_name)) {
                throw std::logic_error("second name is invalid: " + init_second_name);
            }

            if (!right_str(init_port)) {
                throw std::logic_error("port name is invalid: " + init_port);
            }

            if (!(init_cabin_number >= 100 && init_cabin_number <= 500)) {
                throw std::logic_error("cabin number is invalid: " + std::to_string(init_cabin_number));
            }

            if (!(init_cabin_type >= 0 && init_cabin_type <= 3)) {
                throw std::logic_error("cabin type is invalid: " + std::to_string(init_cabin_type));
            }


            Surname = init_Surname;
            Name = init_Name;
            second_name = init_second_name;
            cabin_number = init_cabin_number;
            cabin_type = init_cabin_type;
            port = init_port;


        }
        /// \relates Passenger
        friend std::ofstream &operator<<(std::ofstream &stream, Passenger &passenger);
        /// \relates Passenger
        friend bool operator<(const Passenger &l, const Passenger &r);
        /// \relates Passenger
        friend bool operator>(const Passenger &l, const Passenger &r);
        /// \relates Passenger
        friend bool operator>=(const Passenger &l, const Passenger &r);
        /// \relates Passenger
        friend bool operator<=(const Passenger &l, const Passenger &r);

    private:
        std::string Surname, Name, second_name, port;/*!< поля ФИО,порт */
        int cabin_number, cabin_type;/*!< поля:номер кабины тип кабины */

        //! статическая функция определяет - правильно ли введена строка
        /*!

          \param s - строка
          \return  правильная ли строка или ннет

        */
        static bool right_str(std::string s) {
            if (s == "")
                return false;
            for (auto ch : s) {
                if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '-'))
                    return false;
            }
            return true;
        }

    };

/*!
 *  определяет как будут сравниваться элементы
 */
    bool operator<(const Passenger &l, const Passenger &r) {
        if (l.cabin_number == r.cabin_number) {
            if (l.port == r.port) {
                if (l.Surname == r.Surname) {
                    if (l.Name == r.Name) {
                        return (l.second_name < r.second_name);
                    } else return (l.Name < r.Name);
                } else return (l.Surname < r.Surname);
            } else return (l.port < r.port);
        } else return (l.cabin_number < r.cabin_number);
    }

/*!
 * определяет как будут сравниваться элементы
 */
    bool operator>(const Passenger &l, const Passenger &r) {
        return r < l;

    }
/*!
 *  определяет как будут сравниваться элементы
 */
    bool operator>=(const Passenger &l, const Passenger &r) {
        return !(l < r);
    }/*!
 *  определяет как будут сравниваться элементы
 */

    bool operator<=(const Passenger &l, const Passenger &r) {
        return !(l > r);
    }
    /*!
 *  определяет как будет выводиться объект
 */
    std::ofstream &operator<<(std::ofstream &stream, Passenger &passenger) {
        stream << passenger.Surname << "," << passenger.Name << ","
               << passenger.second_name << "," << passenger.cabin_number << "," << passenger.cabin_type << ","
               << passenger.port;

    }
    /**
       * парсер строки - разбивает строки на строки ФИО,номер кабины,тип кабины ,порт
       *

       * @param[in] s - строка
       * \return объект тип Passanger
       *
       */
    Passenger parse(const std::string s) {
        std::istringstream ss(s);
        std::string Surname, Name, second_name, port;
        int cabin_number, cabin_type;
        std::getline(ss, Surname, ',');

        std::getline(ss, Name, ',');

        std::getline(ss, second_name, ',');


        if (!isdigit(ss.peek()) && ss.peek() != '-') {

            throw std::logic_error("Wrong of  cabin_nummber format : " + s);
        }
        ss >> cabin_number;
        if (ss.peek() != ',') {
            throw std::logic_error("incorrectly formed csv:" + s);
        }
        ss.ignore(1);

        if (!isdigit(ss.peek()) && ss.peek() != '-') {

            throw std::logic_error("Wrong of cabin_type : " + s);
        }
        ss >> cabin_type;
        if (ss.peek() != ',') {
            throw std::logic_error("incorrectly formed csv:" + s);
        }
        ss.ignore(1);
        std::getline(ss, port);
        return Passenger{Surname, Name, second_name, cabin_number, cabin_type, port};
    }
}

#endif SORTING_PASSANGER_HPP
