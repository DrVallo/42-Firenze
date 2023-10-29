/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:37:44 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 10:59:58 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest || src)
	{
		if (dest < src)
			return (ft_memcpy(dest, src, n));
		if (dest > src)
			while (n--)
				((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
