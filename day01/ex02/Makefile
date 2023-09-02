NAME   = Brain
FLAGS  = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address,integer,undefined
CC     = g++
FILES  =	main.cpp 
OBJS   = $(FILES:.cc=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cc
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re