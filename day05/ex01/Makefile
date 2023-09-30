NAME   = From
FLAGS  = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
CC     = clang++
FILES  = main.cpp Bureaucrat.cpp Form.cpp
OBJS   = $(FILES:.cpp=.o)
HEADER = Bureaucrat.hpp Form.hpp

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