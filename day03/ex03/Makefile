NAME   = DiamondTrap
FLAGS  = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
CC     = g++
FILES  = main.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp \
		DiamondTrap.cpp
OBJS   = $(FILES:.cpp=.o)
HEADER = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp DiamondTrap.hpp

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