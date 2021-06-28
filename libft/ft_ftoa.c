/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 13:10:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 23:18:59 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <float.h>

static const double	g_power[] = {
	1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
};

static char	*check_special_values(double n)
{
	if (n != n)
		return (ft_strdup("nan"));
	if (n < -DBL_MAX)
		return (ft_strdup("-inf"));
	if (n > DBL_MAX)
		return (ft_strdup("inf"));
	return (NULL);
}

static void	calc_info(double n, int precision, t_floatinfo *info)
{
	info->str_len = ft_float_len(n, precision);
	if (precision > 9)
		precision = 9;
	if (info->negative)
		info->str_len++;
	info->whole = (unsigned long)n;
	info->tmp = (n - info->whole) * g_power[precision];
	info->frac = (unsigned long)info->tmp;
	info->diff = info->tmp - info->frac;
	if (info->diff > 0.5)
	{
		info->frac++;
		if (info->frac >= g_power[precision])
		{
			info->frac = 0;
			info->whole++;
		}
	}
	else if (!(info->diff < 0.5) && ((info->frac == 0) || (info->frac & 1)))
		info->frac++;
	info->whole_len = ft_unumlen(info->whole, 10);
	info->frac_len = ft_unumlen(info->frac, 10);
	info->zero_pad = 0;
}

static void	write_padding(char *b, int precision, t_floatinfo *info)
{
	size_t	i;

	i = 0;
	info->zero_pad = precision - info->frac_len;
	while (i < info->zero_pad)
		b[info->whole_len + 1 + i++] = '0';
}

static void	write_decimal(char *b, double n, int precision, t_floatinfo *info)
{
	size_t	i;

	if (precision == 0)
	{
		info->diff = n - (double)info->whole;
		if ((!(info->diff < 0.5) || (info->diff > 0.5)) && (info->whole & 1))
			info->whole++;
	}
	else
	{
		if (info->frac_len < (size_t)precision)
			write_padding(b, precision, info);
		if (info->frac == 0)
			b[info->str_len - 1] = '0';
		while (info->frac != 0 && precision--)
		{
			i = info->whole_len + info->zero_pad + info->frac_len--;
			b[i] = '0' + (info->frac % 10);
			info->frac /= 10;
		}
		b[info->whole_len] = '.';
	}
}

char	*ft_ftoa(double n, int precision)
{
	t_floatinfo	info;
	char		*ret;
	char		*ptr;

	ret = check_special_values(n);
	if (ret)
		return (ret);
	info.negative = n < 0.0;
	if (info.negative)
		n = 0 - n;
	calc_info(n, precision, &info);
	ret = (char *)ft_calloc(info.str_len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ptr = ret + info.str_len - 1;
	while (precision-- > 9)
		*ptr-- = '0';
	ptr = ret;
	if (info.negative)
		++ptr;
	write_decimal(ptr, n, ++precision, &info);
	ft_untoa(ptr, info.whole, info.whole_len);
	if (info.negative)
		ret[0] = '-';
	return (ret);
}
