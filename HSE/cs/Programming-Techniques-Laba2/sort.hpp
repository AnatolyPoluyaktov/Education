//
// Created by drope on 26.02.2020.
//

#ifndef LABA2_SORT_HPP
#define LABA2_SORT_HPP
#include<vector>
namespace  algo{
    template < typename T >
    static void my_swap ( T & first , T & second )
    {
        T temp = first;
        first = second ;
        second = temp ;
    }


    template <typename T>
    static size_t partition(std::vector<T>& vec,  size_t i ,size_t j){
        T pvt= vec[(i + j)/2]; // опорный элемент
        while(i <= j){// i и j левый и правый указатель
            while(vec[i] < pvt)
                ++i;
            while(vec[j] > pvt)
                --j;
            if( i>=j )
                break;
            my_swap(vec[i],vec[j]);
            ++i;
            --j;
        }
        return j;
    }
    template< typename T>
    void qick_sort(std::vector<T>& vec,size_t l, size_t r){
        if (l < r){
            size_t q = partition(vec,l,r);
            qick_sort(vec,l,q);
            qick_sort(vec,q+1,r);
        }
    }

}
#endif //LABA2_SORT_HPP
