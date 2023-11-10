/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:10:27 by avallini          #+#    #+#             */
/*   Updated: 2023/11/10 20:16:47 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flags_unsigned_width_and_zero(unsigned int nbr, int flags[])
{
	int	count;

	count = 0;
	if (flags[PREC] >= unsigned_nbr_len(nbr))
		flags[WIDTH] -= flags[PREC];
	else if (!(nbr == 0 && flags[PREC] == 0))
		flags[WIDTH] -= unsigned_nbr_len(nbr);
	while (flags[WIDTH] > 0)
	{
		if (flags[ZERO] && flags[PREC] == -1)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
		flags[WIDTH]--;
	}
	return (count);
}

int	print_unsigned_nbr(unsigned int nbr)
{
	int				count;
	unsigned int	n;

	count = 0;
	if (nbr != 0)
	{
		n = (nbr % 10) + '0';
		count += print_unsigned_nbr(nbr / 10);
		count += write(1, &n, 1);
	}
	return (count);
}

int	print_unsigned_decimal(unsigned int nbr, int flags[])
{
	int	count;
	int	n_len;

	count = 0;
	n_len = unsigned_nbr_len(nbr);
	if (!flags[REV])
		count += print_flags_unsigned_width_and_zero(nbr, flags);
	while (n_len < flags[PREC])
	{
		count += write(1, "0", 1);
		n_len++;
	}
	if (nbr == 0 && (flags[PREC] > 0 || flags[PREC] == -1))
		count += write(1, "0", 1);
	else
		count += print_unsigned_nbr(nbr);
	if (flags[REV])
		count += print_flags_unsigned_width_and_zero(nbr, flags);
	return (count);
}
