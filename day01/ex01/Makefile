NAME   = Zombie
FLAGS  = -Wall -Wextra -Werror -std=c++98 
CC     = g++
HEADER = Zombie.hpp
FILES  =	main.cpp \
			zombieHorde.cpp \
			Zombie.cpp 
OBJS   = $(FILES:.cpp=.o)

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