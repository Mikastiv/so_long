/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 00:32:01 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/15 20:39:42 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	size;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_numlen(n, base_len);
	size = len + 1;
	if (n < 0)
		size += 1;
	ret = (char *)ft_calloc(size, sizeof(char));
	if (!ret)
		return (NULL);
	ft_ntoa_base(ret, n, len, base);
	return (ret);
}
