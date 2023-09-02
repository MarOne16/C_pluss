#include <iostream>

class Megaphone
{
    public:
    void mega(char *str)
    {
        while (*str)
        {
            std::cout << (char)toupper(*str);
            str++;
        }
    }
    void mega_non(void)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
};

int main(int argc, char *argv[])
{
    Megaphone megaphone;
    if (argc < 2)
        megaphone.mega_non();
    else
    {
        while (*(++argv))
            megaphone.mega(*argv);
        std::cout << "\n";
    }        
    return 0;
}
