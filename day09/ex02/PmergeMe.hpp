#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <unistd.h>


class PmergeMe
{
    private:
        int size;
        std::string arg;
        std::string result;
        PmergeMe();
        PmergeMe &operator=(PmergeMe const &other);
        PmergeMe(PmergeMe const &other);
    public:
        std::vector<int> v;
        std::vector<int> v_mainChain;
        std::deque<int> d;
        std::deque<int> d_mainChain;
        typedef std::vector<int>::iterator v_iter;
        typedef std::deque<int>::iterator d_iter;
        PmergeMe(char const *argv[]);
        ~PmergeMe();
        void feedargv(char const *argv[]);
        void pushToContainers();
        void befforAfter(std::string str, bool type) const;
        template <typename T>
        void insertionSort(T &array)
        {
            typename T::iterator it = array.begin();
            typename T::iterator ite = array.end();
            while (it != ite)
            {
                typename T::iterator it2 = it;
                    while (it2 != array.begin() && *it2 < *(it2 - 1))
                    {
                        std::iter_swap(it2, it2 - 1);
                        --it2;
                     }
             ++it;
            }
        }
        template <typename T>
        void myErease(T &array, int num)
        {
            typename T::iterator it = array.begin();
            while (it != array.end()) {
                if (*it == num) {
                    it = array.erase(it);
                } else {
                    ++it;
                }
            }
        }
        template <typename T>
        void    display(T &array)
        {
            for (typename T::iterator it = array.begin(); it != array.end(); it++)
                std::cout << *it << " ";
        }
        template <typename T>
        void creatMainChain(T &array, T &mainChain)
        {
            size_t i = 0;
            size_t max = array.size();
            T tmp;
            T tmp2 = array;
            while (i < max - 1)
            {
                tmp.push_back(tmp2[i]);
                tmp.push_back(tmp2[i + 1]);
                insertionSort(tmp);
                mainChain.push_back(tmp[0]);
                myErease(array, tmp[0]);
                tmp.clear();
                i += 2;
            }
            size = array.size();
        }
        template <typename T>
        void addToChain(T &mainChain, T &Pending)
        {
            int n = 1;
            size_t last_i = 1;
            start:
            last_i = pow(2, n++) - last_i;
            size_t i = last_i;
            if (i > Pending.size())
                i = Pending.size();
            while (i)
            {
                typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), Pending[i - 1]);
                mainChain.insert(it, Pending[i - 1]);
                Pending.erase(Pending.begin() + (i - 1));
                i--;
            }
            if (Pending.size() > 0)
                goto start;
        }
};

bool isPositiveInteger(std::string &str);
