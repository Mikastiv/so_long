/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:37:08 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 08:06:51 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static bool	is_not_valid_char(char c)
{
	return (!(c == WALL_C || c == EMPTY_C || c == PLAYER_C
			|| c == EXIT_C || c == COLLECT_C));
}

bool	has_only_valid_chars(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_str_any(map->grid[i], is_not_valid_char))
			return (false);
		++i;
	}
	return (true);
}

bool	is_valid_map(t_map *map)
{
	char	*err;

	err = NULL;
	if (!is_closed(map))
		err = "The map is not closed!\n";
	if (!is_rect(map))
		err = "The map is not a rectangle!\n";
	if (!has_exit(map))
		err = "The map has no exit!\n";
	if (!has_one_start(map))
		err = "The map has 0 or more than 1 starting position!\n";
	if (!has_collectible(map))
		err = "The map has no collectible!\n";
	if (!has_only_valid_chars(map))
		err = "The map has invalid characters!\n";
	if (err)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err, 2);
		return (false);
	}
	return (true);
}
