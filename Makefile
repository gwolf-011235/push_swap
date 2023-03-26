# text effects
RESET := \033[0m
BOLD := \033[1m
BLACK := \033[30m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m
CYAN := \033[36m
CYAN_B := \033[46m

# directories
SRC_DIR := src
SRC_DIR_B := src/bonus
OBJ_DIR := obj
OBJ_DIR_B := obj/bonus
LIB_DIR := lib
LIB_DIR_FT := $(LIB_DIR)/libft
INC_DIR := include

# include
INC := -I $(INC_DIR) -I lib/libft/include

# libraries
LIB_FT := -L $(LIB_DIR_FT) -l ft 

# compiling
CC := clang
CFLAGS = -Wall -Werror -Wextra
COMPILE = $(CC) $(CFLAGS) $(INC)

# targets
NAME := push_swap
LIBFT := $(LIB_DIR_FT)/libft.a

# progress bar
HIT_TOTAL = $(words $(SRCS))
HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
ECHO = printf "\033[2K\r[`expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`%%] %s"

# source files
SRC :=  main.c \
		check_input.c \
		parse_input.c \
		utils_print.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

# objects
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))

.PHONY: all, clean, fclean, re, debug, bonus, re_bonus
.SILENT:

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(COMPILE) $(OBJS) $(LIB_FT) -o $@
	echo "$(GREEN)$(NAME) created!$(RESET)"

debug: CFLAGS = -g
debug: clean $(NAME)

test: $(NAME)
	echo The following are valid:
	./$(NAME) 1
	./$(NAME) -2
	./$(NAME) 1 -2 3
	./$(NAME) 12345
	./$(NAME) 12345 6789 12 345
	echo
	echo The following are error
	./$(NAME) c 
	./$(NAME) 1d -2 3
	./$(NAME) 12 34a 456 58
	./$(NAME) -12a 12 13

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) message
	$(COMPILE) -c $< -o $@

message:
	printf "$(YELLOW)$(BOLD)compilation$(RESET) [$(BLUE)push_swap$(RESET)]\n"


$(LIBFT):
	printf "$(YELLOW)$(BOLD)compilation$(RESET) [$(BLUE)libft$(RESET)]\n"
	$(MAKE) -C $(LIB_DIR)/libft

clean: 
	printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)push_swap$(RESET)]\n"
	rm -rf $(OBJ_DIR)
	printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

fclean: clean
	rm -rf $(NAME)
	printf "$(RED)removed bin $(NAME)$(RESET)\n"
	printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)libft$(RESET)]\n"
	$(MAKE) --no-print-directory -C $(LIB_DIR_FT) fclean

re: fclean all
	
re_bonus: fclean bonus

