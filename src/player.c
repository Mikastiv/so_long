/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 17:02:59 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 18:16:00 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	get_next_pos(t_player *player, t_dir dir, int *x, int *y)
{
	*x = player->x;
	*y = player->y;
	if (dir == UP)
		*y = player->y - 1;
	else if (dir == DOWN)
		*y = player->y + 1;
	else if (dir == LEFT)
		*x = player->x - 1;
	else if (dir == RIGHT)
		*x = player->x + 1;
}

bool	is_valid_move(t_map *map, t_player *player, t_dir dir)
{
	int	x;
	int	y;

	get_next_pos(player, dir, &x, &y);
	if (map->grid[y][x] == WALL_C)
		return (false);
	return (true);
}
