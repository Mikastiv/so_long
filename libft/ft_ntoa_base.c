/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:39:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 22:54:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ntoa_base(char *b, long n, size_t len, const char *base)
{
	long	base_len;
	long	i;

	base_len = ft_strlen(base);
	if (n < 0)
		*b++ = '-';
	while (len > 0)
	{
		i = n % base_len;
		if (i < 0)
			i *= -1;
		b[--len] = base[i];
		n /= base_len;
	}
}
