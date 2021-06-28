/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:13:41 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 16:14:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static bool	is_collectible(char c)
{
	return (c == COLLECT_C);
}

int	count_collects(t_map *map)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < map->height)
	{
		count += ft_str_count_if(map->grid[i], is_collectible);
		++i;
	}
	return (count);
}
