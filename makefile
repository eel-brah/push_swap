CC := cc
CFLAGS := -Wall -Wextra -Werror

AR := ar
ARFLAGS := rcs

LIBFTDIR := ./libft
LIBFT := $(LIBFTDIR)/libft.a

SRC_DIRS := .
INCLUDE := push_swap.h

SRC_FILES := push_swap.c push_swap_core_utils_0.c push_swap_core_utils_1.c push_swap_core_utils_2.c \
				push_swap_operations_0.c push_swap_operations_1.c push_swap_operations_2.c \
        		push_swap_utils_0.c push_swap_utils_1.c

OBJ_FILES := $(SRC_FILES:.c=.o)

NAME := push_swap

all: $(NAME)

$(NAME): $(SRC_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(SRC_FILES) $(LIBFT) -o $@

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