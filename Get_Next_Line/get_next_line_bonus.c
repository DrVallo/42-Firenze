/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:31:46 by avallini          #+#    #+#             */
/*   Updated: 2023/10/25 19:24:15 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*lstnew(int fd)
{
	char	*str;
	int		*n;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	n = (int *)malloc(sizeof(int));
	*n = fd;
	new->fd = n;
	new->saved_buf = str;
	new->next = NULL;
	return (new);
}

t_list	*file_is_alredy_read(int fd, t_list **list)
{
	t_list	*new_node;
	t_list	*p_list;

	p_list = *list;
	new_node = NULL;
	while (p_list != NULL)
	{
		if (*p_list->fd == fd)
			return (p_list);
		p_list = p_list->next;
	}
	new_node = lstnew(fd);
	new_node->next = *list;
	*list = new_node;
	return (new_node);
}

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

void	read_line(int fd, t_list *node)
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
			node->saved_buf = str_join(node->saved_buf, buf);
		}
	}
	free(buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;
	t_list			*node;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	node = file_is_alredy_read(fd, &list);
	if (!contain_nl(node->saved_buf))
		read_line(fd, node);
	line = str_cpy(node->saved_buf, nl_pos(node->saved_buf));
	node->saved_buf = upd_svd_buf(node->saved_buf,
			nl_pos(node->saved_buf));
	if (!line || line[0] == '\0')
		return (NULL);
	return (line);
}
