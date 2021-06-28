/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 01:50:27 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 22:55:51 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_base(unsigned int n, const char *base)
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
