/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:39:56 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 11:06:36 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*r1;
	char	*r2;

	r1 = (char *)s1;
	r2 = (char *)s2;
	while (n--)
	{
		if (*r1 != *r2)
			return (*(unsigned char *)r1 - *(unsigned char *)r2);
		r1++;
		r2++;
	}
	return (0);
}
