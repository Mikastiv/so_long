/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:57:42 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 16:14:32 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static bool	is_player(char c)
{
	return (c == PLAYER_C);
}

static bool	is_collectible(char c)
{
	return (c == COLLECT_C);
}

bool	is_valid_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".ber", len) != 0)
	{
		ft_putstr_fd("Error\nThe map needs to be a .ber file!\n", 2);
		return (false);
	}
	return (true);
}

bool	has_one_start(t_map *map)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		count += ft_str_count_if(map->grid[i], is_player);
		++i;
	}
	return (count == (size_t)1);
}

bool	has_collectible(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_str_any(map->grid[i], is_collectible))
			return (true);
		++i;
	}
	return (false);
}
