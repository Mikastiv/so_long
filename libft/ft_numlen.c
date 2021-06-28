/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 18:21:02 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 22:55:10 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_numlen(long n, long radix)
{
	size_t	len;

	len = 0;
	while (n / radix != 0)
	{
		n /= radix;
		++len;
	}
	return (len + 1);
}
