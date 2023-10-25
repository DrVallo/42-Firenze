/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:21:24 by avallini          #+#    #+#             */
/*   Updated: 2023/10/24 12:41:57 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*str_cpy(char *str, int stop)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = str_len(str);
	if (!str || len == 0)
		return (NULL);
	cpy = (char *)malloc(sizeof(char) * len + 1);
	while (str[i] && i <= stop)
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*str_join(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (str_len(s1) + str_len(s2)) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	free(s1);
	return (str);
}

int	contain_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	nl_pos(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
