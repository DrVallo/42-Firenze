/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:11:25 by avallini          #+#    #+#             */
/*   Updated: 2023/11/08 19:12:59 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c, int flags[])
{
	int	count;

	count = 0;
	if (flags[WIDTH] > 0)
		flags[WIDTH]--;
	if (flags[REV])
	{
		count += write(1, &c, 1);
		while (flags[WIDTH]--)
			count += write(1, " ", 1);
		return (count);
	}
	while (flags[WIDTH]--)
		count += write(1, " ", 1);
	count += write(1, &c, 1);
	return (count);
}

int	write_str(char *str, int flags[])
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	if (flags[PREC] == -1)
	{
		while (*str)
			count += write(1, str++, 1);
	}
	else if (flags[PREC] == 0)
		return (count);
	else
	{
		while (*str && flags[PREC]-- > 0)
			count += write(1, str++, 1);
	}
	return (count);
}

void	get_width_precision(char *str, int flags[])
{
	if (!str)
		return ;
	if (flags[PREC] != -1)
	{
		if ((size_t)flags[PREC] <= ft_strlen(str))
			flags[WIDTH] -= flags[PREC];
		else
			flags[WIDTH] -= ft_strlen(str);
		return ;
	}
	flags[WIDTH] -= ft_strlen(str);
	return ;
}

int	print_str(char *str, int flags[])
{
	int	count;

	count = 0;
	if (!str && (flags[PREC] >= 6 || flags[PREC] == -1))
		return (print_str("(null)", flags));
	get_width_precision(str, flags);
	if (flags[REV])
	{
		count += write_str(str, flags);
		while (flags[WIDTH]-- > 0)
			count += write(1, " ", 1);
		return (count);
	}
	while (flags[WIDTH]-- > 0)
		count += write(1, " ", 1);
	count += write_str(str, flags);
	return (count);
}
