/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:38:19 by avallini          #+#    #+#             */
/*   Updated: 2023/10/20 20:00:15 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*limit_case_return(int n)
{
	char	*str;

	if (n == INT_MAX)
		str = ft_strdup("2147483647");
	else if (n == INT_MIN)
		str = ft_strdup("-2147483648");
	else
		str = ft_strdup("0");
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		neg;

	neg = 0;
	digits = n_len(n);
	if (!n || n == INT_MIN || n == INT_MAX)
		return (limit_case_return(n));
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		neg = 1;
		str[0] = '-';
	}
	str[digits] = '\0';
	while (digits-- && !(!digits && neg))
	{
		str[digits] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

/*#include <stdio.h>
int	main (void)
{
	char *res = ft_itoa(-1234);
    printf("%s\n", res);
    free(res);
}*/
