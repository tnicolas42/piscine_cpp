NAME = megaphone

SRCS = megaphone.cpp

CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

all:
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(SRCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re