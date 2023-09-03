NAME   = Zombie
FLAGS  = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address,integer,undefined
CC     = g++
HEADER = Zombie.hpp
FILES  =	main.cpp \
			newZombie.cpp \
			rendomChump.cpp \
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