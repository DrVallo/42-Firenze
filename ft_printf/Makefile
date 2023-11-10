# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 21:14:37 by avallini          #+#    #+#              #
#    Updated: 2023/11/01 15:06:13 by avallini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC =	ft_printf.c \
	ft_decimal.c \
	ft_extra_flags.c \
	ft_hexadecimal.c \
	ft_ptr.c \
	ft_str.c \
	ft_unsigned_decimal.c \
	ft_utils.c \

OBJS	= $(SRC:.c=.o)

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus
