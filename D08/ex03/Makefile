NAME = ex03

SRCS_DIR	= .
OBJS_DIR	= objs

SRC =	main.cpp \
		Brainfuck.cpp \
		AInstruction.cpp \
		IncrPtr.cpp \
		DecrPtr.cpp \
		IncrData.cpp \
		DecrData.cpp \
		CoutData.cpp \
		GetInput.cpp \
		WhileStart.cpp \
		WhileEnd.cpp

HEADS =	Brainfuck.hpp \
		AInstruction.hpp \
		IncrPtr.hpp \
		DecrPtr.hpp \
		IncrData.hpp \
		DecrData.hpp \
		CoutData.hpp \
		GetInput.hpp \
		WhileStart.hpp \
		WhileEnd.hpp

INC		= $(addprefix -I , $(HEADS))
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))

CC =		clang++
CFLAGS =	-std=c++98 -Wall -Wextra -Weverything -Werror

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf "create -> $(NAME)\n"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(INC)

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

re: fclean
	@make all

exec: all
	@printf "exec $(NAME)\n"
	@./$(NAME)

.PHONY: all clean fclean re exec
