/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:33:04 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 14:08:21 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = c;
	while (*s && *s != chr)
		s++;
	if (*s == '\0' && chr != '\0')
		return (NULL);
	return ((char *)s);
}

/*#include <stdio.h>
int	main (void)
{

	const char	*name = "teste";
	char *ret = ft_strchr(name, 't' + 256);
	if (ret != NULL)
		printf("%s\n", ret);
	else
		printf("NULL\n");
}*/
