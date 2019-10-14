NAME = PhoneContact

SRCS_DIR	= .
OBJS_DIR	= objs

SRC = main.cpp PhoneContact.cpp

HEADS = PhoneContact.hpp

INC = $(addprefix -I , $(HEADS))
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

CC = g++
CFLAGS = -std=c++98 -Wall -Wextra #-Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)


$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
	rm -f $(SRC)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re