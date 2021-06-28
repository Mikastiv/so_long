/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:47:50 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 22:56:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long n, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_unumlen(n, base_len);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_untoa_base(ret, n, len, base);
	return (ret);
}
