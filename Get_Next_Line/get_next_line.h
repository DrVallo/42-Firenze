/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:21:08 by avallini          #+#    #+#             */
/*   Updated: 2023/09/10 17:08:01 by avallini         ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*read_line(int fd, char **saved_buf);
char	*upd_svd_buf(char *str, int start);
int		contain_nl(char *str, int ret_len);
char	*strjoin(char *s1, char *s2);
char	*ft_strcpy(char *str, int stop);
int		ft_strlen(char *str);

#endif
