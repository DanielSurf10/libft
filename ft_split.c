/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:49:53 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/26 14:45:18 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	next_word_size(char const *s, char sep)
{
	size_t	size;

	size = 0;
	while (s[size] != sep && s[size] != '\0')
		size++;
	return (size);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_iter;
	size_t	word_size;
	size_t	word_count;
	char	**split;

	i = 0;
	word_iter = 0;
	word_size = 0;
	word_count = count_words(s, c);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[word_count] = NULL;
	while (word_iter < word_count)
	{
		while (s[i] == c)
			i++;
		word_size = next_word_size(s + i, c);
		split[word_iter] = ft_substr(s + i, 0, word_size);
		i += word_size;
		word_iter++;
	}
	return (split);
}