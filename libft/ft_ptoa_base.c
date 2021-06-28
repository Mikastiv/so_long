/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 23:27:35 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/17 22:56:11 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ptoa_base(void *ptr, const char *base)
{
	char	*ret;
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_unumlen((size_t)ptr, base_len);
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_untoa_base(ret, (size_t)ptr, len, base);
	return (ret);
}
