/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:59:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 22:04:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t	ft_wchar_size(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (5);
	if (c > 0xFFFF)
		return (4);
	else if (c > 0x7FF)
		return (3);
	else if (c > 0x7F)
		return (2);
	else
		return (1);
}
