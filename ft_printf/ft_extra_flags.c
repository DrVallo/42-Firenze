/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:55:04 by avallini          #+#    #+#             */
/*   Updated: 2023/11/10 20:17:13 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_flag(const char **str, int flags[], va_list args)
{
	if (**str == '*')
	{
		flags[WIDTH] = va_arg(args, int);
		(*str)++;
	}
	else
	{
		while (**str >= '0' && **str <= '9')
		{
			flags[WIDTH] = (flags[WIDTH] * 10) + (**str - '0');
			(*str)++;
		}
	}
}

void	check_sign_rev_flags(const char **str, int flags[])
{
	while (**str == '+' || **str == '-')
	{
		if (**str == '+')
			flags[SIGN] = 1;
		if (**str == '-')
			flags[REV] = 1;
		(*str)++;
	}
}

void	check_extra_flags_1(const char **str, int flags[], va_list args)
{
	init_array(flags, ARRAY_SIZE);
	while (**str == '#' || **str == '0' || **str == '-'
		|| **str == '+' || **str == ' ')
	{
		if (**str == ' ')
		{
			flags[SPACE] = 1;
			(*str)++;
		}
		check_sign_rev_flags(str, flags);
		if (**str == '0')
		{
			flags[ZERO] = 1;
			(*str)++;
		}
		if (**str == '#')
		{
			flags[HASH] = 1;
			(*str)++;
		}
	}
	check_extra_flags_2(str, flags, args);
}

void	check_extra_flags_2(const char **str, int flags[], va_list args)
{
	check_width_flag(str, flags, args);
	if (**str == '.')
	{
		flags[PREC] = -1;
		(*str)++;
		if (**str == '*')
		{
			flags[PREC] = va_arg(args, int);
			if (flags[PREC] < 0)
				flags[PREC] = -1;
			(*str)++;
		}
		else
		{
			flags[PREC] = 0;
			while (**str >= '0' && **str <= '9')
			{
				flags[PREC] = (flags[PREC] * 10) + (**str - '0');
				(*str)++;
			}
		}
	}
}
