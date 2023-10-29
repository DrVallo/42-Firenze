/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:39:12 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 14:08:17 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = ft_strlen(s);
	chr = c;
	if (chr == '\0')
		return (&((char *)s)[i]);
	while (i >= 0)
	{
		if (((char *)s)[i] == chr)
			return (&((char *)s)[i]);
		i--;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main ()
{
	char *ptr = ft_strrchr("Ciao1234", '9');
	if (ptr == NULL)
		printf("NULL\n");
	else
		printf("%s\n", ptr);
}*/
