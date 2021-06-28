/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:27:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/05 20:40:55 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
		while (len-- > 0)
			*d++ = *s++;
	else
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len-- > 0)
			*d-- = *s--;
	}
	return (dst);
}
