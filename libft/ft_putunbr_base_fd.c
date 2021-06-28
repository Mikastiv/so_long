/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:53:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/07 18:06:00 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ULL unsigned long long

static void	putnbr_recursive(ULL n, const char *base, ULL radix, int fd)
{
	if (n / radix != 0)
		putnbr_recursive(n / radix, base, radix, fd);
	ft_putchar_fd(base[n % radix], fd);
}

void	ft_putunbr_base_fd(ULL n, const char *base, int fd)
{
	putnbr_recursive(n, base, (ULL)ft_strlen(base), fd);
}
