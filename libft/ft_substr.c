/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:09:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/12 14:33:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	newlen;
	size_t	strlen;
	char	*substr;

	strlen = ft_strlen(s);
	newlen = 0;
	if (strlen > start)
		newlen = ft_strnlen(s + start, len);
	else
		start = strlen;
	substr = (char *)ft_calloc(newlen + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, (newlen + 1) * sizeof(char));
	return (substr);
}
