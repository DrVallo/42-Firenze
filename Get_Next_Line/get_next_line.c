/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:21:20 by avallini          #+#    #+#             */
/*   Updated: 2023/09/10 17:02:18 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char **saved_buf)
{
	char	*line;
	char	*buf;
	int		buf_size;

	buf_size = 1;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	buf[0] = '\0';
	while (buf_size > 0 && !contain_nl(buf, 0))
	{
		buf_size = read(fd, buf, BUFFER_SIZE);
		if (buf_size > 0)
		{
			buf[buf_size] = '\0';
			*saved_buf = strjoin(*saved_buf, buf);
		}
	}
	free(buf);
	line = ft_strcpy(*saved_buf, contain_nl(*saved_buf, 1));
	*saved_buf = upd_svd_buf(*saved_buf, contain_nl(*saved_buf, 1));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_buf;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, &saved_buf);
	if (!line || line[0] == '\0')
		return (NULL);
	return (line);
}
