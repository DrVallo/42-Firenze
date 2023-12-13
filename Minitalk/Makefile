# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 21:46:10 by avallini          #+#    #+#              #
#    Updated: 2023/12/13 21:55:29 by avallini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c utils.c
SRC_SERVER = server.c utils.c
SRC_CLIENT_BONUS = client_bonus.c utils_bonus.c
SRC_SERVER_BONUS = server_bonus.c utils_bonus.c

OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)
bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)
$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(OBJS_CLIENT_BONUS)
$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER_BONUS) $(OBJS_SERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_CLIENT)
	rm -f $(OBJS_SERVER)
	rm -f $(OBJS_CLIENT_BONUS)
	rm -f $(OBJS_SERVER_BONUS)

fclean: clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT_BONUS)
	rm -f $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: all clean fclean re
