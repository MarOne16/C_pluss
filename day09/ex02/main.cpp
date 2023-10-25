
#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
  try
  {
      if (argc < 2)
          throw std::runtime_error("Error: wrong number of arguments");
      PmergeMe p(argv);
      p.pushToContainers();
      std::cout << "Before: ";
      p.display(p.v);
      ////use Vector/////////////////////////////////////////////////////
      clock_t start = clock();
      p.creatMainChain(p.v);
      p.insertionSort(p.v_mainChain);
      p.addToChain(p.v_mainChain, p.v);;
      clock_t end = clock();
      double Vtime = (double)(end - start) / 1000;
      std::cout << std::endl;
      std::cout << "After: ";
      p.display(p.v_mainChain);
      ///////// Deque ////////////////////////////////////////////////////
      start = clock();
      p.creatMainChain(p.d);
      p.insertionSort(p.d_mainChain);
      p.addToChain(p.d_mainChain, p.d);
      end = clock();
      double Dtime = (double)(end - start) / 1000;
      ///////// display results //////////////////////////////////////////
      std::cout << std::endl;
      std::cout << "Time to process a range of " << p.v_mainChain.size() << " elements with std::Vector "\
       << std::setprecision(3) << std::fixed << Vtime << " us" << std::endl;
      std::cout << "Time to process a range of " << p.d_mainChain.size() << " elements with std::Deque "\
        << std::setprecision(3) << std::fixed << Dtime << " us" << std::endl;
      
  }
  catch(std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}