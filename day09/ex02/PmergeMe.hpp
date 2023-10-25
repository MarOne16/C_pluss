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
        int Jacobsthal;
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
        int  getJacobsthal(int n);
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
        void creatMainChain(T &array)
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
                this->v_mainChain.push_back(tmp[0]);
                myErease(array, tmp[0]);
                tmp.clear();
                i += 2;
            }
            size = array.size();
        }
        template <typename T>
        void addToChain(T &mainChain, T &Pending)
        {
            size_t i = -1;
            while (++i < Pending.size())
            {
                typename T::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), Pending[i]);
                mainChain.insert(it, Pending[i]);
            }
            Pending.clear();
        }
};

bool isPositiveInteger(std::string &str);
