NAME   = Phone_Book
FLAGS  = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address,integer,undefined
CC     = g++
HEADER = Phone_Book.h
FILES  = Phone_Book.cc
OBJS   = $(FILES:.cc=.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cc
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re