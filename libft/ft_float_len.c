/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 22:07:40 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 22:09:46 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_float_len(double n, int precision)
{
	size_t	len;

	len = ft_numlen((long)n, 10);
	if (precision > 0)
		len += (size_t)precision + 1;
	return (len);
}
