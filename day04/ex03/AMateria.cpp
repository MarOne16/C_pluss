#include "AMateria.hpp"

void AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const &AMateria::getType() const
{
	return (this->type);
}
