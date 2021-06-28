/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:54:10 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/15 20:25:47 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}
