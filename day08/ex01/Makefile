NAME   = Span_exe
FLAGS  = -Wall -Wextra -Werror -std=c++98
CC     = c++
FILES  = main.cpp Span.cpp
OBJS   = $(FILES:.cpp=.o)
HEADER = Span.hpp

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