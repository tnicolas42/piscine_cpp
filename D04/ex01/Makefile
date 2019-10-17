NAME = ex01

SRCS_DIR	= .
OBJS_DIR	= objs

SRC =	main.cpp \
		AWeapon.cpp \
		PlasmaRifle.cpp \
		PowerFist.cpp \
		Enemy.cpp \
		SuperMutant.cpp \
		RadScorpion.cpp \
		Character.cpp

HEADS =	AWeapon.hpp \
		PlasmaRifle.hpp \
		PowerFist.hpp \
		Enemy.hpp \
		SuperMutant.hpp \
		RadScorpion.hpp \
		Character.hpp

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