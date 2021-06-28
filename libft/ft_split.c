/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:27:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/15 20:26:13 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static size_t	ft_count_words(const char *s, const char c)
{
	size_t		count;
	const char	*w_start;
	bool		in_word;

	count = 0;
	in_word = 0;
	w_start = s;
	while (*s)
	{
		if (in_word && *s == c)
			++count;
		if (*s == c)
			in_word = false;
		else
			in_word = true;
		if (!in_word)
			w_start = s;
		++s;
	}
	if (in_word)
		++count;
	return (count);
}

static char	*ft_get_word(const char *s, int len, char c)
{
	char	*word;

	if (*s == c)
	{
		++s;
		--len;
	}
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, (len + 1) * sizeof(char));
	return (word);
}

static void	ft_append_words(char **arr, const char *s, char c)
{
	const char	*w_start;
	int			i;
	bool		in_word;

	w_start = s;
	in_word = false;
	i = 0;
	while (*s)
	{
		if (in_word && *s == c)
			arr[i++] = ft_get_word(w_start, s - w_start, c);
		if (*s == c)
			in_word = false;
		else
			in_word = true;
		if (!in_word)
			w_start = s;
		++s;
	}
	if (in_word)
		arr[i++] = ft_get_word(w_start, s - w_start, c);
}

static void	ft_free_str_array(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		++i;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	word_count;
	size_t	i;

	word_count = ft_count_words(s, c);
	ret = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	ft_append_words(ret, s, c);
	i = 0;
	while (i < word_count)
	{
		if (ret[i++] == NULL)
		{
			ft_free_str_array(ret, word_count);
			return (NULL);
		}
	}
	return (ret);
}
