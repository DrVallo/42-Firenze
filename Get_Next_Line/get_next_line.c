/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:21:20 by avallini          #+#    #+#             */
/*   Updated: 2023/10/25 19:03:32 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*upd_svd_buf(char *str, int start)
{
	int		i;
	char	*line;

	if (!str)
		return (str);
	if (str[start])
		start++;
	i = str_len(str + start);
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
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

void	read_line(int fd, char **saved_buf)
{
	char	*buf;
	int		buf_size;

	buf_size = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf[0] = '\0';
	while (buf_size > 0 && !contain_nl(buf))
	{
		buf_size = read(fd, buf, BUFFER_SIZE);
		if (buf_size > 0)
		{
			buf[buf_size] = '\0';
			*saved_buf = str_join(*saved_buf, buf);
		}
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static char	*saved_buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!contain_nl(saved_buf))
		read_line(fd, &saved_buf);
	line = str_cpy(saved_buf, nl_pos(saved_buf));
	saved_buf = upd_svd_buf(saved_buf, nl_pos(saved_buf));
	if (!line || line[0] == '\0')
		return (NULL);
	return (line);
}
