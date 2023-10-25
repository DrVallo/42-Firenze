/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:05:48 by avallini          #+#    #+#             */
/*   Updated: 2023/10/25 19:27:38 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				*fd;
	char			*saved_buf;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	read_line(int fd, t_list *node);
char	*upd_svd_buf(char *str, int start);
int		contain_nl(char *str);
int		nl_pos(char *str);
char	*str_join(char *s1, char *s2);
char	*str_cpy(char *str, int stop);
int		str_len(char *str);
t_list	*file_is_alredy_read(int fd, t_list **list);
t_list	*lstnew(int fd);

#endif
