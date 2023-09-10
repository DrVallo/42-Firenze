/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:35:59 by avallini          #+#    #+#             */
/*   Updated: 2023/09/10 17:04:56 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *str, int stop)
{
	int		i;
	int		len;
	char	*cpy;
	
	i = 0;
	len = ft_strlen(str);
	if (!str)
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

char	*strjoin(char *s1, char *s2)
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
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

int	cnt_nl(char *str, int ret_len)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (i == ft_strlen(str))
	{
		if (!ret_len)
			return (0);
	}
	return (i);
}

char	*upd_svd_buf(char *str, int start)
{
	int		i;
	char	*line;

	if (!str)
		return (str);
	if (str[start])
		start++;
	i = ft_strlen(str + start);
	line = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[start + i])
	{
		line[i] = str[start + i];
		i++;
	}
	line[i] = '\0';
	free(str);
	return (line);
}
