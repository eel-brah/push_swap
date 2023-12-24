CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcs

LIBFTDIR := ./libft
LIBFT := $(LIBFTDIR)/libft.a

SRC_DIRS := srcs
INCLUDE := push_swap.h

SRC_FILES := push_swap.c push_swap_core_utils_0.c push_swap_core_utils_1.c push_swap_core_utils_2.c \
				push_swap_operations_0.c push_swap_operations_1.c push_swap_operations_2.c \
				push_swap_utils_0.c push_swap_utils_1.c push_swap_utils_2.c merge_sort.c \
				push_swap_sort_0.c push_swap_sort_1.c push_swap_sort_2.c push_swap_sort_3.c \
				push_swap_sort_4.c push_swap_sort_5.c push_swap_sort_6.c

SRC_FILES := $(addprefix $(SRC_DIRS)/,$(SRC_FILES))

OBJ_FILES := $(SRC_FILES:.c=.o)

NAME := push_swap

all: $(NAME)

$(NAME): $(SRC_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_FILES) $(LIBFT) -o $@

$(LIBFT): $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)

bonus: all

clean:
	$(MAKE) clean -C $(LIBFTDIR) 
	rm -rf $(OBJ_FILES)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR) 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus