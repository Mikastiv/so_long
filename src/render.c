/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 23:53:14 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/28 15:52:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <mlx.h>

static void	put_pixel_scale(t_buffer *buf, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < SCALE)
	{
		i = 0;
		while (i < SCALE)
			put_pixel(buf, x + i++, y + j, color);
		++j;
	}
}

static int	get_tile_index(char c)
{
	if (c == WALL_C)
		return (WALL);
	if (c == COLLECT_C)
		return (COLLECT);
	if (c == PLAYER_C)
		return (PLAYER);
	if (c == EXIT_C)
		return (EXIT);
	return (EMPTY);
}

static void	draw_tile(t_game *game, int index, int x, int y)
{
	int	i;
	int	j;
	int	color;

	x = x * SCALE * SP_SIZE;
	y = y * SCALE * SP_SIZE;
	j = 0;
	while (j < game->sprites[index]->height)
	{
		i = 0;
		while (i < game->sprites[index]->width)
		{
			color = get_pixel(game->sprites[index], i, j);
			put_pixel_scale(game->back, x + i * SCALE, y + j * SCALE, color);
			++i;
		}
		++j;
	}
}

void	draw_game(t_game *game)
{
	int	x;
	int	y;
	int	index;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			index = get_tile_index(game->map->grid[y][x]);
			draw_tile(game, index, x, y);
			++x;
		}
		++y;
	}
	swap_buffers(&game->front, &game->back);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->front->img, 0, 0);
}
