/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:12:49 by mleblanc          #+#    #+#             */
/*   Updated: 2021/05/25 22:22:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static unsigned int	get_header(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (0xF1);
	if (c > 0xFFFF)
		return (0xF0);
	else if (c > 0x7FF)
		return (0xE0);
	else if (c > 0x7F)
		return (0xC0);
	else
		return (0x00);
}

static unsigned int	get_mask(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (0x03);
	if (c > 0xFFFF)
		return (0x07);
	else if (c > 0x7FF)
		return (0x0F);
	else if (c > 0x7F)
		return (0x1F);
	else
		return (0x00);
}

static int	get_shift(wint_t c)
{
	if (c > 0x3FFFFFF)
		return (24);
	if (c > 0xFFFF)
		return (18);
	else if (c > 0x7FF)
		return (12);
	else if (c > 0x7F)
		return (6);
	else
		return (-1);
}

void	ft_putwchar_fd(wint_t c, int fd)
{
	unsigned int	header;
	unsigned int	mask;
	int				shift;

	header = get_header(c);
	mask = get_mask(c);
	shift = get_shift(c);
	if (ft_wchar_size(c) == 1)
		ft_putchar_fd((char)c, fd);
	else
	{
		ft_putchar_fd(header | (((c >> shift) & mask)), fd);
		shift -= 6;
	}
	while (shift >= 0)
	{
		ft_putchar_fd(0x80 | ((c >> shift) & 0x3F), fd);
		shift -= 6;
	}
}
