
NAME  = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
CC    = g++
FILES = Mega_Phone.cpp
OBJS  = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
