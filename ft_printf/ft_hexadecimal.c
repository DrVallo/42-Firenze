/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:36:15 by avallini          #+#    #+#             */
/*   Updated: 2023/11/10 12:53:46 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flags_hex_width_and_zero(char *str, int flags[], int saved_prec)
{
	int	count;

	count = 0;
	if (!(saved_prec == 0 && (ft_strlen(str) == 1 && str[0] == '0')))
		flags[WIDTH] -= ft_strlen(str);
	while (flags[WIDTH] > 0)
	{
		if (flags[ZERO] && saved_prec == -1)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
		flags[WIDTH]--;
	}
	return (count);
}

char	*str_join(char *s1, char *s2)
{
	int		i;
	char	*str;
	char	*s2_cpy;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s2_cpy = s2;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
	{
		str[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2++;
		i++;
	}
	str[i] = '\0';
	free(s2_cpy);
	return (str);
}

void	convert_hex(unsigned int nbr, char c, char **str)
{
	if (nbr >= 16)
	{
		convert_hex(nbr / 16, c, str);
		convert_hex(nbr % 16, c, str);
	}
	else if (nbr < 10)
		*str = char_join(*str, (nbr % 16) + 48);
	else
	{
		if (c == 'x')
			*str = char_join(*str, (nbr % 16) + 87);
		else
			*str = char_join(*str, (nbr % 16) + 55);
	}
}

char	*get_str_hex(unsigned int nbr, char c, int flags[])
{
	char	*str;

	str = NULL;
	if (flags[HASH] && nbr != 0)
	{
		if (c == 'x')
			str = ft_strdup("0x");
		else
			str = ft_strdup("0X");
	}
	else
		str = ft_strdup("");
	if (!str)
		return (0);
	convert_hex(nbr, c, &str);
	return (str);
}

int	print_hex(unsigned int nbr, char c, int flags[])
{
	int		count;
	int		s_len;
	int		saved_prec;
	char	*str;

	count = 0;
	str = get_str_hex(nbr, c, flags);
	s_len = ft_strlen(str);
	saved_prec = flags[PREC];
	flags[PREC] = -1;
	while (s_len < saved_prec)
	{
		str = str_join("0", str);
		s_len++;
	}
	if (!flags[REV])
		count += print_flags_hex_width_and_zero(str, flags, saved_prec);
	if (!(saved_prec == 0 && (ft_strlen(str) == 1 && str[0] == '0')))
		count += print_str(str, flags);
	if (flags[REV])
		count += print_flags_hex_width_and_zero(str, flags, saved_prec);
	free(str);
	return (count);
}
