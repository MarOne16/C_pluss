#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <ctime>



class PmergeMe
{
    private:
        std::string arg;
        std::string result;
        PmergeMe();
        PmergeMe &operator=(PmergeMe const &other);
        PmergeMe(PmergeMe const &other);
    public:
        std::vector<int> v;
        std::deque<int> d;
        typedef std::vector<int>::iterator v_iter;
        typedef std::deque<int>::iterator d_iter;
        PmergeMe(std::string &arg);
        ~PmergeMe();
        void pushToContainers(std::string &str);
        void befforAfter(std::string str) const;
        template <typename T>
        void insertionSort(T &array)
        {
            typename T::iterator it = array.begin();
            typename T::iterator ite = array.end();
            typename T::iterator it2;
            while (it != ite)
            {
                it2 = it;
                while (it2 != array.begin() && *it2 < *(it2 - 1))
                {
                    std::iter_swap(it2, it2 - 1);
                    --it2;
                }
                ++it;
            }
        }
        template <typename T>
        void mergeSort(T &array)
        {
            if (array.size() <= 10)
            {
                insertionSort(array);
                return;
            }
            typename T::iterator middle = array.begin() + (array.size() / 2);
            T left(array.begin(), middle);
            T right(middle, array.end());
            mergeSort(left);
            mergeSort(right);
            std::merge(left.begin(), left.end(), right.begin(), right.end(), array.begin());
        }
        template <typename T>
        void merge(T &leftBegin, T &leftEnd, T &rightBegin, T &rightEnd, T &result)
        {
            while (leftBegin != leftEnd && rightBegin != rightEnd)
            {
                if (*leftBegin < *rightBegin)
                {
                    *result = *leftBegin;
                    ++leftBegin;
                }
                else
                {
                    *result = *rightBegin;
                    ++rightBegin;
                }
                ++result;
            }
        }
};
bool isPositiveInteger(std::string &str);