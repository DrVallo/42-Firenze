/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:32:03 by avallini          #+#    #+#             */
/*   Updated: 2023/10/18 21:34:39 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		substr = (char *)malloc(sizeof(char));
	else if (len < ft_strlen(s))
		substr = (char *)malloc(sizeof(char) * (len + 1));
	else
		substr = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	if (!substr)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[i + start] && i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
	}
	substr[i] = '\0';
	return (substr);
}

/*#include <stdio.h>
int main (void)
{
	const char	*name = "Abcdefghijklmno";

	printf("%s\n", ft_substr(name, 6, 7));
}*/
