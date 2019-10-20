NAME = ft_retro

SRCS_DIR	= .
OBJS_DIR	= objs

SRC =	main.cpp \
		Screen.class.cpp \
		SpaceDebris.class.cpp \
		AEntity.cpp \
		Player.cpp \
		Enemy.cpp \
		EnemySmallMissile.cpp \
		EnemyBigMissile.cpp \
		EnemyHoriz.cpp \
		BulletsContainer.cpp \
		Weapon.cpp \
		AScreenElement.class.cpp \
		AScreenRenderedElement.class.cpp \
		Colors.cpp \
		AFleet.cpp \
		EnemyFleet.cpp \
		Bullet.cpp \
		AContainer.class.cpp \
		SpaceDebrisContainer.class.cpp \
		PlayerInput.class.cpp

HEADS =	AEntity.hpp \
		AFleet.hpp \
		Bullet.hpp \
		BulletsContainer.hpp \
		Colors.hpp \
		Defines.hpp \
		Enemy.hpp \
		EnemySmallMissile.hpp \
		EnemyBigMissile.hpp \
		EnemyHoriz.hpp \
		EnemyFleet.hpp \
		AContainer.class.hpp \
		AScreenElement.class.hpp \
		AScreenRenderedElement.class.hpp \
		Player.hpp \
		Screen.class.hpp \
		SpaceDebris.class.hpp \
		SpaceDebrisContainer.class.hpp \
		Texture.hpp \
		Weapon.hpp \
		PlayerInput.class.hpp

INC = $(addprefix -I , $(HEADS))
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

CC = clang++
CFLAGS = -std=c++98 -Wall -Wextra -g3 #-Werror
LFLAGS = -lncurses

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf "create -> $(NAME)\n"
	@$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(NAME) $(INC)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADS)
	@printf "compile -> $@\n"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)


$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
	@printf "clean\n"
	@rm -f $(OBJS)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@printf "fclean\n"
	@rm -f $(NAME)

re: fclean all

exec: all
	@printf "exec $(NAME)\n"
	@./$(NAME)

.PHONY: all clean fclean re exec
