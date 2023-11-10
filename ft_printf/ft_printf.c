/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 21:17:53 by avallini          #+#    #+#             */
/*   Updated: 2023/10/27 21:17:53 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_flag(const char **str, va_list args)
{
	int	count;
	int	flags[ARRAY_SIZE];

	count = 0;
	check_extra_flags_1(str, flags, args);
	if (**str == 'c')
		count += print_char(va_arg(args, int), flags);
	else if (**str == 's')
		count += print_str(va_arg(args, char *), flags);
	else if (**str == 'p')
		count += print_void_ptr(va_arg(args, unsigned long int), flags);
	else if (**str == 'd' || **str == 'i')
		count += print_decimal(va_arg(args, int), flags);
	else if (**str == 'u')
		count += print_unsigned_decimal(va_arg(args, unsigned int), flags);
	else if (**str == 'x' || **str == 'X')
		count += print_hex(va_arg(args, unsigned int), **str, flags);
	else if (**str == '%')
		count += write(1, "%", 1);
	else
	{
		count += write(1, "%", 1);
		count += write(1, *str, 1);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += convert_flag(&str, args);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
