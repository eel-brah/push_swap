CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcs

INCLUDE_DIR := include
SRC_DIRS := srcs
BONUS_DIRS := srcs/bonus
LIBFTDIR := ./libft

LIBFT := $(LIBFTDIR)/libft.a
INCLUDE := $(INCLUDE_DIR)/push_swap.h
INCLUDE_BONUS := $(INCLUDE_DIR)/push_swap_bonus.h
SRC_FILES := push_swap.c push_swap_core_utils_0.c push_swap_core_utils_1.c push_swap_core_utils_2.c \
				push_swap_operations_0.c push_swap_operations_1.c push_swap_operations_2.c \
				push_swap_utils_0.c push_swap_utils_1.c push_swap_utils_2.c merge_sort.c \
				push_swap_sort_0.c push_swap_sort_1.c push_swap_sort_2.c push_swap_sort_3.c \
				push_swap_sort_4.c push_swap_sort_5.c push_swap_sort_6.c 
SRC_FILES := $(addprefix $(SRC_DIRS)/,$(SRC_FILES))
BONUS_FILES := checker_bonus.c push_swap_core_utils_0_bonus.c push_swap_core_utils_1_bonus.c \
				push_swap_core_utils_2_bonus.c push_swap_utils_0_bonus.c push_swap_utils_1_bonus.c \
				checker_gnl_bonus.c push_swap_operations_0_bonus.c push_swap_operations_1_bonus.c \
				push_swap_operations_2_bonus.c
BONUS_FILES := $(addprefix $(BONUS_DIRS)/,$(BONUS_FILES))

NAME := push_swap
BONUS_NAME := checker

all: $(NAME)

$(NAME): $(SRC_FILES) $(LIBFT) $(INCLUDE)
	@echo "\033[0;34mCompiling \033[1;34m$(NAME) ...\033[0m"
	@$(CC) $(CFLAGS) $(SRC_FILES) $(LIBFT) -o $@
	@echo "\033[1;32m$(NAME) \033[0;32mhas been compiled\033[0m"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_FILES) $(LIBFT) $(INCLUDE_BONUS)
	@echo "\033[0;34mCompiling \033[1;34m$(BONUS_NAME) ...\033[0m"
	@$(CC) $(CFLAGS) $(BONUS_FILES) $(LIBFT) -o $@
	@echo "\033[1;32m$(BONUS_NAME) \033[0;32mhas been compiled\033[0m"

$(LIBFT): $(LIBFTDIR)
	@echo "\033[0;34mCompiling \033[1;34mlibft.a ..."
	@$(MAKE) -C $(LIBFTDIR)
	@echo "\033[1;32mlibft.a \033[0;32mhas been compiled"

clean:
	@$(MAKE) clean -C $(LIBFTDIR) 
	@echo "\033[0;31mCleaning\033[0m"
	@echo "\033[0;32mDone\033[0m"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR) 
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus