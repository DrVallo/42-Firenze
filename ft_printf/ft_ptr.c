/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:40:47 by avallini          #+#    #+#             */
/*   Updated: 2023/11/01 08:48:11 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*char_join(char *s1, char s2)
{
	int		i;
	char	*str;
	char	*s1_cpy;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1_cpy = s1;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	str[i] = s2;
	i++;
	str[i] = '\0';
	free(s1_cpy);
	return (str);
}

void	convert_hex_ptr(unsigned long int nbr, char **str)
{
	if (nbr >= 16)
	{
		convert_hex_ptr(nbr / 16, str);
		convert_hex_ptr(nbr % 16, str);
	}
	else if (nbr < 10)
		*str = char_join(*str, (nbr % 16) + 48);
	else
		*str = char_join(*str, (nbr % 16) + 87);
}

int	print_void_ptr(unsigned long int ptr, int flags[])
{
	int		count;
	char	*str;

	count = 0;
	str = NULL;
	str = ft_strdup("0x");
	if (!str)
		return (0);
	if (!ptr)
		count += print_str("(nil)", flags);
	else
	{
		convert_hex_ptr(ptr, &str);
		count += print_str(str, flags);
	}
	free(str);
	return (count);
}
