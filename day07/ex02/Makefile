NAME   = Array
FLAGS  = -Wall -Wextra -Werror -std=c++98 #-g -fsanitize=address
CC     = c++
FILES  = main.cpp
OBJS   = $(FILES:.cpp=.o)
HEADER = Array.hpp Array.tpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re