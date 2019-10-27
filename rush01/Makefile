NAME = ft_gkrellm
PROJECT_NAME = $(shell echo $(NAME) | tr a-z A-Z)# name in MAJUSCULE

ARGS =

SRCS_DIR	= srcs
OBJS_DIR	= objs
INC_DIR		= includes

SRC =	main.cpp \
		SystemMonitor.cpp \
		module/Attribute.cpp \
		module/AMonitorModule.cpp \
		module/ATitleMonitorModule.cpp \
		module/AAttributeListMonitorModule.cpp \
		module/NameModule.cpp \
		module/OSInfoModule.cpp \
		module/TimeModule.cpp \
		module/NetworkModule.cpp \
		module/CPUModule.cpp \
		module/RAMModule.cpp \
		module/FileModule.cpp \
		module/UptimeModule.cpp \
		display/AMonitorDisplay.cpp \
		display/SFMLMonitorDisplay.cpp \
		display/NcursesMonitorDisplay.cpp \
		display/CoutMonitorDisplay.cpp \

HEAD =	SystemMonitor.hpp \
		module/Attribute.hpp \
		module/IMonitorModule.hpp \
		module/AMonitorModule.hpp \
		module/ATitleMonitorModule.hpp \
		module/NameModule.hpp \
		module/AAttributeListMonitorModule.hpp \
		module/OSInfoModule.hpp \
		module/TimeModule.hpp \
		module/NetworkModule.hpp \
		module/CPUModule.hpp \
		module/RAMModule.hpp \
		module/FileModule.hpp \
		module/UptimeModule.hpp \
		display/IMonitorDisplay.hpp \
		display/AMonitorDisplay.hpp \
		display/SFMLMonitorDisplay.hpp \
		display/NcursesMonitorDisplay.hpp \
		display/CoutMonitorDisplay.hpp \

CC = g++
DEBUG_FLAGS = -g3 -fsanitize=address
LIBS_FLAGS = -L ~/.brew/lib -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -rpath ~/.brew/lib -lncurses
LIBS_INC =  -I ~/.brew/Cellar/sfml/2.5.1/include/ -I ~/.brew/include
CFLAGS = -Wno-deprecated -Ofast -Wall -Wextra -Werror

HEADS	= $(addprefix $(INC_DIR)/, $(HEAD))
OBJS	= $(addprefix $(OBJS_DIR)/, $(SRC:.cpp=.o))
INC		= -I $(INC_DIR) $(addprefix -I , $(addprefix $(INC_DIR)/, $(dir $(HEAD)))) $(LIBS_INC)

NORMAL = "\x1B[0m"
RED = "\x1B[31m"
GREEN = "\x1B[32m"
YELLOW = "\x1B[33m"
BLUE = "\x1B[34m"
MAGENTA = "\x1B[35m"
CYAN = "\x1B[36m"
WHITE = "\x1B[37m"
BOLD = "\e[1m"
LIGHT = "\e[2m"
ITALIC = "\e[3m"
ULINE = "\e[4m"

START = @printf $(GREEN)$(BOLD)"$(PROJECT_NAME)\n--------------------\n"$(NORMAL)
END = @printf $(GREEN)$(BOLD)"--------------------\n"$(NORMAL)

all:
	$(START)
	@make $(NAME)
	$(END)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS_FLAGS)
	@printf $(CYAN)"-> create program : $(NAME)\n"$(NORMAL)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@printf $(YELLOW)"-> $<\n"$(NORMAL)


$(OBJS_DIR):
	@mkdir -p $(dir $(OBJS))

clean:
	$(START)
	@printf $(RED)"-x remove .o files\n"$(NORMAL)
	@rm -rf $(OBJS_DIR)
	$(END)

fclean: clean
	$(START)
	@printf $(RED)"-x remove $(NAME)\n"$(NORMAL)
	@rm -f $(NAME)
	$(END)

re: fclean
	@make

exec:
	@make
	@printf $(MAGENTA)$(BOLD)"EXEC $(PROJECT_NAME)\n--------------------\n"$(NORMAL)
	@./$(NAME) $(ARGS)
	@printf $(MAGENTA)$(BOLD)"--------------------\n"$(NORMAL)

.PHONY: all clean fclean re exec
