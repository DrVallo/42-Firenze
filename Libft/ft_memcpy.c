/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:37:28 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 12:25:05 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest != NULL || src != NULL)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (dest || src)
	{
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	return (dest);
}*/

/*#include <stdio.h>
int main ()
{
	char *a = "Ciao";
	char *dst = malloc(5);
	dst[0] = '\0';
	ft_memcpy(dst, a, 10);
	if (!dst)
		printf("NULL\n");
	else
		printf("%s\n", dst);
}*/
