NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Werror -Wextra -Wall

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif
 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif
 
SRC = src/main.c \
	src/hooks.c \
	src/map_check.c \
	src/map_draw.c \
	src/map_init.c \
	src/map_utils.c \
	src/player.c \
	src/utils.c \
	src/window_management.c

SRC_BONUS = src_bonus/main_bonus.c \
	src_bonus/hooks_bonus.c \
	src_bonus/map_check_bonus.c \
	src_bonus/map_draw_bonus.c \
	src_bonus/map_init_bonus.c \
	src_bonus/map_utils_bonus.c \
	src_bonus/player_bonus.c \
	src_bonus/enemy_bonus.c \
	src_bonus/utils_bonus.c \
	src_bonus/utils_2_bonus.c \
	src_bonus/window_management_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(MLX_LIB) $(NAME)
bonus: $(MLX_LIB) $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)
 
clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus