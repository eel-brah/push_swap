CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcs

INCLUDE_DIR := include
SRC_DIRS := src
BONUS_DIRS := bonus
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
OBJ_FILES := $(SRC_FILES:.c=.o)
BONUS_FILES := checker_bonus.c push_swap_core_utils_0_bonus.c push_swap_core_utils_1_bonus.c \
				push_swap_core_utils_2_bonus.c push_swap_utils_0_bonus.c push_swap_utils_1_bonus.c \
				checker_gnl_bonus.c push_swap_operations_0_bonus.c push_swap_operations_1_bonus.c \
				push_swap_operations_2_bonus.c
BONUS_FILES := $(addprefix $(BONUS_DIRS)/,$(BONUS_FILES))
BONUS_OBJ_FILES := $(BONUS_FILES:.c=.o)

NAME := push_swap
BONUS_NAME := checker

all: lib $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $@
	@echo "\033[1;32m$(NAME) \033[0;32mhas been compiled\033[0m"

$(SRC_DIRS)/%.o: $(SRC_DIRS)/%.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: lib $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) $(LIBFT) -o $@
	@echo "\033[1;32m$(BONUS_NAME) \033[0;32mhas been compiled\033[0m"

$(BONUS_DIRS)/%.o: $(BONUS_DIRS)/%.c $(INCLUDE_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

lib:
	@$(MAKE) -C $(LIBFTDIR)

clean:
	@echo "\033[0;31mCleaning\033[0m"
	@$(MAKE) clean -C $(LIBFTDIR) 
	@rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)
	@echo "\033[0;32mDone\033[0m"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR) 
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus lib