/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:21:08 by avallini          #+#    #+#             */
/*   Updated: 2023/10/25 19:27:31 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	read_line(int fd, char **saved_buf);
char	*upd_svd_buf(char *str, int start);
int		contain_nl(char *str);
int		nl_pos(char *str);
char	*str_join(char *s1, char *s2);
char	*str_cpy(char *str, int stop);
int		str_len(char *str);

#endif
