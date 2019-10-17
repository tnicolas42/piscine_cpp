NAME = ex03

SRCS_DIR	= .
OBJS_DIR	= objs

SRC = AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

HEADS = AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp

INC = $(addprefix -I , $(HEADS))
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

CC = clang++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)


$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
	rm -f $(OBJS)
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re