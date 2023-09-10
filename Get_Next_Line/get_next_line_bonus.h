/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:05:48 by avallini          #+#    #+#             */
/*   Updated: 2023/09/10 17:07:34 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H_
#define _GET_NEXT_LINE_H_

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
	int				*fd;
	char			*saved_buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*read_line(int fd, t_list *node);
char	*upd_svd_buf(char *str, int start);
int		cnt_nl(char *str, int ret_len);
char	*strjoin(char *s1, char *s2);
char	*ft_strcpy(char *str, int stop);
int		ft_strlen(char *str);
t_list	*file_is_alredy_read(int fd, t_list **list);
t_list	*lstnew(int fd);

#endif
