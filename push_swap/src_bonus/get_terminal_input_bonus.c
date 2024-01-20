/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminal_input_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:56:05 by avallini          #+#    #+#             */
/*   Updated: 2024/01/13 12:58:53 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

char	*add_char_to_str(char *str, char c)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = str_len(str);
	new_str = (char *)malloc(sizeof(char) * (len + 2));
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i] = c;
	new_str[i + 1] = '\0';
	return (new_str);
}

char	*get_terminal_input(void)
{
	int		buf_size;
	char	*buf;
	char	*str;

	buf = (char *)malloc(sizeof(char));
	str = (char *)malloc(sizeof(char));
	buf[0] = '\0';
	str[0] = '\0';
	buf_size = 1;
	while (buf_size > 0 && *buf != '\n')
	{
		buf_size = read(0, buf, 1);
		if (buf_size <= 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		if (*buf != '\n')
			str = add_char_to_str(str, *buf);
	}
	free(buf);
	return (str);
}
