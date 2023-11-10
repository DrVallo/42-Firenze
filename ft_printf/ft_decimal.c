/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:58:22 by avallini          #+#    #+#             */
/*   Updated: 2023/11/10 18:54:47 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flags_width_and_zero(int nbr, int flags[])
{
	int	count;

	count = 0;
	if (nbr < 0 || (flags[SIGN] && nbr < 0))
		flags[WIDTH]--;
	if (flags[PREC] >= nbr_len(nbr))
		flags[WIDTH] -= flags[PREC];
	else if (!(nbr == 0 && flags[PREC] == 0))
		flags[WIDTH] -= nbr_len(nbr);
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

int	print_sign(int nbr, int flags[])
{
	if (nbr < 0)
		return (write(1, "-", 1));
	else if (flags[SIGN] && nbr >= 0)
		return (write(1, "+", 1));
	else if (flags[SPACE] && nbr >= 0)
		return (write(1, " ", 1));
	return (0);
}

int	print_nbr(int nbr)
{
	int	count;
	int	n;

	count = 0;
	if (nbr == INT_MAX)
		return (write(1, "2147483647", 10));
	else if (nbr == INT_MIN)
		return (write(1, "2147483648", 10));
	if (nbr != 0)
	{
		n = (nbr % 10) + '0';
		count += print_nbr(nbr / 10);
		count += write(1, &n, 1);
	}
	return (count);
}

int	print_n(int nbr, int flags[])
{
	int	count;
	int	n_len;

	count = 0;
	n_len = nbr_len(nbr);
	while (n_len < flags[PREC])
	{
		count += write(1, "0", 1);
		n_len++;
	}
	if (nbr == 0 && (flags[PREC] > 0 || flags[PREC] == -1))
		count += write(1, "0", 1);
	else if (nbr == 0 && flags[PREC] == 0)
		return (count);
	else
		count += print_nbr(nbr);
	return (count);
}

int	print_decimal(int nbr, int flags[])
{
	int	count;
	int	base_nbr;

	count = 0;
	base_nbr = nbr;
	if ((flags[SIGN] && base_nbr >= 0) || (flags[SPACE] && base_nbr >= 0))
		flags[WIDTH]--;
	if (!flags[REV])
	{
		if (flags[ZERO] && flags[PREC] == -1)
			count += print_sign(base_nbr, flags);
		count += print_flags_width_and_zero(base_nbr, flags);
	}
	if (nbr < 0)
		nbr *= -1;
	if (!flags[ZERO] || flags[PREC] != -1)
		count += print_sign(base_nbr, flags);
	count += print_n(nbr, flags);
	if (flags[REV])
		count += print_flags_width_and_zero(base_nbr, flags);
	return (count);
}
