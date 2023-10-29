/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:40:11 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 11:07:04 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_size;

	i = 0;
	little_size = ft_strlen(little);
	if (!little_size)
		return ((char *)big);
	if (!len)
		return (NULL);
	while (big[i] && i + little_size <= len)
	{
		if (!ft_strncmp(&big[i], little, little_size))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main ()
{
	printf("%s\n", ft_strnstr("abcdefghijklmnopqrstuvwxyz", "lmno", 17));
	char *ptr = ft_strnstr("Foo Bar Baz", "Bar", 10);
	if (ptr == NULL)
		printf("NULL\n");
	else
		printf("%s\n", ptr);
}*/
