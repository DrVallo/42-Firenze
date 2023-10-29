/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:06:11 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 13:34:26 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;
	int		i;

	str = NULL;
	len = ft_strlen(s1);
	i = 0;
	if (s1 && set)
	{
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && i < len)
			len--;
		str = (char *)malloc(sizeof(char) * (len - i + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[i], (len - i + 1));
	}
	return (str);
}
