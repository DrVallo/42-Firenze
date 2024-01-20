NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Werror -Wextra -Wall

SRC = src/main.c \
	src/check_data.c \
	src/get_args_data.c \
	src/init_data.c \
	src/list.c \
	src/operations_2.c \
	src/operations_3.c \
	src/operations.c \
	src/quick_sort.c \
	src/sort_a.c \
	src/sort_b.c \
	src/utils.c

SRC_BONUS = src_bonus/main_bonus.c \
	src_bonus/get_terminal_input_bonus.c \
	src_bonus/str_to_operations_bonus.c \
	src_bonus/operations_2_bonus.c \
	src_bonus/operations_3_bonus.c \
	src_bonus/operations_bonus.c \
	src_bonus/check_data_bonus.c \
	src_bonus/get_args_data_bonus.c \
	src_bonus/init_data_bonus.c \
	src_bonus/list_bonus.c \
	src_bonus/quick_sort_bonus.c \
	src_bonus/sort_a_bonus.c \
	src_bonus/sort_b_bonus.c \
	src_bonus/utils_bonus.c


OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
