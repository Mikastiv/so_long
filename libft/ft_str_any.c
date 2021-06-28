/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_any.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:36:42 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/24 16:16:00 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_str_any(const char *s, bool(*f)(char))
{
	while (*s)
	{
		if (f(*s))
			return (true);
		++s;
	}
	return (false);
}
