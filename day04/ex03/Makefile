NAME   = AMateria
FLAGS  = -Wall -Wextra -Werror -std=c++98
CC     = clang++
FILES  = main.cpp AMateria.cpp Character.cpp Ice_Cure.cpp MateriaSource.cpp
OBJS   = $(FILES:.cpp=.o)
HEADER = AMateria.hpp Character.hpp Ice_Cure.hpp IMateriaSource.hpp MateriaSource.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re