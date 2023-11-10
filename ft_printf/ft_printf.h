/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:40:22 by avallini          #+#    #+#             */
/*   Updated: 2023/11/10 20:16:45 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define ARRAY_SIZE 7
# define ZERO 0
# define WIDTH 1
# define REV 2
# define SIGN 3
# define SPACE 4
# define HASH 5
# define PREC 6

int		ft_printf(const char *str, ...);
int		convert_flag(const char **str, va_list args);
int		print_flags_width_and_zero(int nbr, int flags[]);
int		print_sign(int nbr, int flags[]);
int		print_nbr(int nbr);
int		print_n(int nbr, int flags[]);
int		print_decimal(int nbr, int flags[]);
void	check_width_flag(const char **str, int flags[], va_list args);
void	check_sign_rev_flags(const char **str, int flags[]);
void	check_extra_flags_1(const char **str, int flags[], va_list args);
void	check_extra_flags_2(const char **str, int flags[], va_list args);
int		print_flags_hex_width_and_zero(char *str, int flags[], int saved_prec);
char	*str_join(char *s1, char *s2);
void	convert_hex(unsigned int nbr, char c, char **str);
char	*get_str_hex(unsigned int nbr, char c, int flags[]);
int		print_hex(unsigned int nbr, char c, int flags[]);
char	*char_join(char *s1, char s2);
void	convert_hex_ptr(unsigned long int nbr, char **str);
int		print_void_ptr(unsigned long int ptr, int flags[]);
int		print_char(int c, int flags[]);
int		write_str(char *str, int flags[]);
void	get_width_precision(char *str, int flags[]);
int		print_str(char *str, int flags[]);
int		print_flags_unsigned_width_and_zero(unsigned int nbr, int flags[]);
int		print_unsigned_nbr(unsigned int nbr);
int		print_unsigned_decimal(unsigned int nbr, int flags[]);
int		nbr_len(int nbr);
int		unsigned_nbr_len(unsigned int nbr);
void	init_array(int arr[], int size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);

#endif
