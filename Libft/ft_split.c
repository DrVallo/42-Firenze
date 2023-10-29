/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:46:08 by avallini          #+#    #+#             */
/*   Updated: 2023/10/14 11:11:12 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *str, char c)
{
	size_t	words;
	size_t	new_word;

	words = 0;
	new_word = 0;
	while (*str)
	{
		if (*str != c && !new_word)
		{
			new_word = 1;
			words++;
		}
		else if (*str == c)
			new_word = 0;
		str++;
	}
	return (words);
}

static char	**alloc_word(char const *s, char c, char **split, size_t s_len)
{
	size_t	i;
	size_t	split_i;
	size_t	word_len;

	i = 0;
	split_i = 0;
	word_len = 0;
	while (i < s_len + 1 && s_len > 0)
	{
		if (s[i] == c || !s[i])
		{
			if (word_len > 0)
			{
				split[split_i] = (char *)ft_calloc(word_len + 1, sizeof(char));
				if (split[split_i])
					ft_strlcpy(split[split_i], &s[i - word_len], word_len + 1);
				word_len = 0;
				split_i++;
			}
		}
		else
			word_len++;
		i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	s_len;
	char	**split;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	words = words_count(s, c);
	split = (char **)ft_calloc(sizeof(char *), words + 1);
	if (!split)
		return (NULL);
	split = alloc_word(s, c, split, s_len);
	split[words] = NULL;
	return (split);
}
