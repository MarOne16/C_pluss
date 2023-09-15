#if !defined(BRAIN_HPP)
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string *ideas;
    const static int ideasCount = 100;
public:
    Brain();
    Brain(const Brain &brain);
    ~Brain();
    Brain &operator=(const Brain &brain);
    std::string getIdea(int index) const;
    void setIdea(int index, std::string idea);
};

#endif // BRAIN_HPP
