NAME   = abstarct
FLAGS  = -Wall -Wextra -Werror -std=c++98
CC     = clang++
FILES  = main.cpp Animal.cpp
OBJS   = $(FILES:.cpp=.o)
HEADER = Animal.hpp

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