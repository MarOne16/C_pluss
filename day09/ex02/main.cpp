#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc != 2)
            throw std::runtime_error("Error: wrong number of arguments");
        std::string arg(argv[1]);
        PmergeMe p(arg);
        p.pushToContainers(arg);
        p.befforAfter("Before: ");
        //use Vector/////////////////////////////////////////////////////
        clock_t start = clock();
        p.mergeSort(p.v);
        clock_t end = clock();
        double Vtime = (double)(end - start) / 1000;
        //use Deque//////////////////////////////////////////////////////
        start = clock();
        p.mergeSort(p.d);
        end = clock();
        double Dtime = (double)(end - start) / 1000;
        //display results////////////////////////////////////////////////
        p.befforAfter("After:  ");
        for (PmergeMe::v_iter it = p.v.begin(); it != p.v.end(); it++)
            std::cout << *it << " ";
        std::cout << ": Time to process a range of " << p.v.size() << " elements with std::Vector " << std::setprecision(3) << std::fixed << Vtime << " us" << std::endl;
        for (PmergeMe::d_iter it = p.d.begin(); it != p.d.end(); it++)
            std::cout << *it << " ";
        std::cout << ": Time to process a range of " << p.d.size() << " elements with std::Deque " << std::setprecision(3) << std::fixed << Dtime << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}