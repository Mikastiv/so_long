/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 20:34:07 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/06 18:51:02 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;

	size = ft_strlen(s1) + 1;
	s2 = (char *)ft_calloc(size, sizeof(char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, size * sizeof(char));
	return (s2);
}
