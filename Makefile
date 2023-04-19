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
TEST_DIR := tests

# include
INC := -I $(INC_DIR) -I lib/libft/include

# libraries
LIB_FT := -L $(LIB_DIR_FT) -l ft

# compiling
CC := cc
CFLAGS = -g
COMPILE = $(CC) $(CFLAGS) $(INC)

# targets
NAME := push_swap
LIBFT := $(LIB_DIR_FT)/libft.a
NAME_CHECKER := checker

# progress bar
HIT_TOTAL = $(words $(SRCS))
HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
ECHO = printf "\033[2K\r[`expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`%%] %s"

# source files
SRC :=	main.c \
		check_input.c \
		moves_exec.c \
		moves.c \
		moves2.c \
		moves_queue.c \
		parse_input.c \
		prep_input.c \
		sort_simple.c \
		sort_complex.c \
		sort_chunks.c \
		sort_next_move.c \
		utils_string.c \
		utils_sort.c \
		utils_sort2.c \
		queue.c \
		terminate.c \
		print_moves.c \
		print_stacks.c \
		try_open.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

SRC_CHECKER := 	checker_bonus.c \
				checker_utils_bonus.c \
				check_input.c \
				parse_input.c \
				prep_input.c \
				moves_exec.c \
				moves.c \
				moves2.c \
				utils_string.c \
				utils_sort.c \
				utils_sort2.c \
				print_moves.c \
				queue.c \
				terminate.c
SRCS_CHECKER := $(addprefix $(SRC_DIR)/, $(SRC))

# objects
OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))
OBJ_CHECKER := $(SRC_CHECKER:.c=.o)
OBJS_CHECKER := $(addprefix $(OBJ_DIR)/, $(OBJ_CHECKER))

# headers
HEADER := 	push_swap.h \
			check_input.h \
			parse_input.h \
			prep_input.h
HEADERS := $(addprefix $(INC_DIR)/, $(HEADER))

.PHONY: all, clean, fclean, re, debug, bonus, re_bonus
.SILENT:

all: CFLAGS = -Wall -Werror -Wextra
all: clean $(NAME)
	echo "$(GREEN)ALL DONE!$(RESET)"

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	$(COMPILE) $(OBJS) $(LIB_FT) -o $@
	echo "$(GREEN)$(NAME) created!$(RESET)"

debug: $(NAME)
	echo "$(GREEN)DEBUG ready!$(RESET)"

$(NAME_CHECKER): $(LIBFT) $(OBJS_CHECKER) $(HEADERS)
	$(COMPILE) $(OBJS_CHECKER) $(LIB_FT) -o $@
	echo "$(GREEN)$(NAME_CHECKER) created!$(RESET)"

$(OBJ_DIR):
	mkdir -p $@

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
	rm -rf $(NAME_CHECKER)
	printf "$(RED)removed bin $(NAME_CHECKER)$(RESET)\n"
	printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)libft$(RESET)]\n"
	$(MAKE) --no-print-directory -C $(LIB_DIR_FT) fclean

re: fclean all

re_bonus: fclean bonus
