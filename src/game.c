/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:51:18 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/28 17:24:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_utils.h"
#include <stdlib.h>

static bool	init_buffers(t_game *game)
{
	game->front = new_buffer(game->mlx, game->width, game->height);
	if (!game->front)
		return (false);
	game->back = new_buffer(game->mlx, game->width, game->height);
	if (!game->back)
	{
		free_buffer(game->mlx, game->front);
		return (false);
	}
	return (true);
}

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = map;
	game->width = map->width * SCALE * SP_SIZE;
	game->height = map->height * SCALE * SP_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game));
	game->mlx_win = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	if (!game->mlx_win)
		return (free_game(game));
	if (!init_buffers(game))
		return (free_game(game));
	get_player_pos(game->map, &game->player.x, &game->player.y);
	return (game);
}

void	*free_game(t_game *game)
{
	size_t		i;

	free_buffer(game->mlx, game->front);
	free_buffer(game->mlx, game->back);
	i = 0;
	while (i < N_SPRITE)
	{
		if (game->mlx && game->sprites[i])
			free_sprite(game->mlx, game->sprites[i]);
		i++;
	}
	if (game->mlx && game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->map)
		free_map(game->map);
	destroy_mlx(game->mlx);
	free(game);
	return (NULL);
}

void	move_player(t_game *game, t_dir dir)
{
	int	x;
	int	y;

	game->done = false;
	get_next_pos(&game->player, dir, &x, &y);
	if (!is_valid_move(game->map, &game->player, dir))
		return ;
	if (game->map->grid[y][x] == COLLECT_C)
		--game->map->n_collect;
	if (game->map->grid[y][x] == EXIT_C && game->map->n_collect != 0)
		return ;
	else if (game->map->grid[y][x] == EXIT_C && game->map->n_collect == 0)
		game->done = true;
	game->map->grid[y][x] = PLAYER_C;
	game->map->grid[game->player.y][game->player.x] = EMPTY_C;
	game->player.x = x;
	game->player.y = y;
	++game->player.moves;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->player.moves, 1);
	ft_putchar_fd('\n', 1);
}
