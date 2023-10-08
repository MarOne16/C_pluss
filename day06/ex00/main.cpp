#include "ScalarConverte.hpp"

int main(int argc, char **argv)
{

    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <value>" << std::endl;
        return 1;
    }
    try
    {
        int total = 0;
        std::string av = argv[1];
        ScalarConverte sc(av);
        for (size_t i = 0; i < av.length(); i++)
        {
            if (av[i] == '.')
                total++;
        }
        if (total > 1)
            throw ScalarConverte::ImpossibleExep();
        sc.printChar();
        sc.printInt();
        sc.printFloat();
        sc.printDouble();
        
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}