/**
 * @file
 * @brief Файл, содержащий реализации сортировок: выбором,простыми вставками ,быстрой сортировки(quick sort).
 * @details поля сортировки :номер каюты,порт назначения,Фио
 */
/**
* @file main.cpp
* @brief в этом файле считываются данные из файла,сортируются , замеряется время
* @details поля сортировки :номер каюты,порт назначения,Фио
*/
//сортировка номер каюты-> порт назначения -> Фио
#ifndef SORTING_SORT_HPP
#define SORTING_SORT_HPP

#include<vector>
/**
 * @namespace algo
 * @brief Пространство имен содержащее все функции сортировок
 */
namespace algo {
    /**
       * меняет значения объектов местами
       * @tparam T - в который будет инстанциироваться пользовательский тип Passenger

       * @param[in] first - перый объект, second - второй объект
       *
       */

    template<typename T>
    static void my_swap(T &first, T &second) {
        T temp = first;
        first = second;
        second = temp;
    }
    /**
        * Реализует сортировку выбором
        * @tparam T - в который будет инстанциироваться пользовательский тип Passenger

        * @param &vec - ссылка на вектор объектов
        *
        */
    template<typename T>
    void choice_sort(std::vector<T> &vec) {// сортировка выбором
        int min;
        /*ищу элемент минимальный элемент
 * и вставляю его на место перед последним минимальным вставленным*/
        for (size_t i = 0; i < vec.size() - 1; ++i) {
            min = i;
            for (size_t j = (i + 1); j < vec.size(); ++j) {
                if (vec[j] < vec[min]) // ищем минимальный элемент
                    min = j;
            }
            my_swap(vec[i], vec[min]);
        }
    }
    /**
       * Реализует сортировку вставками
       * @tparam T - в который будет инстанциироваться пользовательский тип Passenger

       * @param &vec - ссылка на вектор объектов
       *
       */
    template<typename T>
    void insertion_sort(std::vector<T> &vec) {// сортировка простыми вставками
        int j;
        for (size_t i = 1; i <
                           vec.size(); ++i) { // начиная со 2 ,беру элемент и перемещаю его влево пока не встречу перед ним меньшего
            j = i;
            while (j - 1 >= 0) {
                if (vec[j - 1] <= vec[j])
                    break;
                my_swap(vec[j - 1], vec[j]);
                --j;
            }
        }

    }
    /**
       * эта функция реализует разбивание вектора на 2 других вектора,в которых один вектор имеет
       * все элемент < опорного элемента и 2 вектор имеет все элемент >опорного элемента
       * @tparam T - в который будет инстанциироваться пользовательский тип Passenger

       * @param &vec - ссылка на вектор объектов
       * @param i- левая гранница вектора , j-правая граница вектора
       * \return новую правую границу переданного вектора
       *
       *
       */

    template<typename T>
    static size_t partition(std::vector<T> &vec, size_t i, size_t j) {
        T pvt = vec[(i + j) / 2]; // опорный элемент
        while (i <= j) {// i и j левый и правый указатель
            while (vec[i] < pvt)
                ++i;
            while (vec[j] > pvt)
                --j;
            if (i >= j)
                break;
            my_swap(vec[i], vec[j]);
            ++i;
            --j;
        }
        return j;
    }
/**
       * Реализует сбыструю сортировку
       * @tparam T - в который будет инстанциироваться пользовательский тип Passenger

       * @param &vec - ссылка на вектор объектов
       * @param l- левая гранница вектора , r-правая граница вектора
       *
       *
       */
    template<typename T>
    void qick_sort(std::vector<T> &vec, size_t l, size_t r) {
        if (l < r) {
            size_t q = partition(vec, l, r);
            qick_sort(vec, l, q);
            qick_sort(vec, q + 1, r);
        }
    }

}
#endif //SORTING_SORT_HPP
