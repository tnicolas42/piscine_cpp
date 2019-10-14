NAME = megaphone

SRCS = megaphone.cpp

CC = clang++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

all:
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re