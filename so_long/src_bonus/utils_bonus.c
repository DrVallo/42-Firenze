/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:11:41 by avallini          #+#    #+#             */
/*   Updated: 2023/12/24 13:17:56 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd(((n % 10) + '0'), fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}

char	*add_char_to_str(char *str, char c, t_game *game)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	new_str = (char *)malloc(sizeof(char) * (str_len(str) + 2));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	if (c == '\n')
		game->rows++;
	if (c == 'C')
		game->collectibles++;
	return (new_str);
}
