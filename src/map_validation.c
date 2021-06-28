/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:32:53 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 16:15:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static bool	is_not_wall(char c)
{
	return (c != WALL_C);
}

static bool	is_exit(char c)
{
	return (c == EXIT_C);
}

bool	is_closed(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((i == 0 || i == map->height - 1)
			&& ft_str_any(map->grid[i], is_not_wall))
			return (false);
		if (map->grid[i][0] != WALL_C
			|| map->grid[i][ft_strlen(map->grid[i]) - 1] != WALL_C)
			return (false);
		++i;
	}
	return (true);
}

bool	is_rect(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != map->width)
			return (false);
		++i;
	}
	return (true);
}

bool	has_exit(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_str_any(map->grid[i], is_exit))
			return (true);
		++i;
	}
	return (false);
}
