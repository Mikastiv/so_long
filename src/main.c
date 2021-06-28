#include <mlx.h>
#include "libft.h"
#include "map_validation.h"
#include "buffer.h"
#include "game.h"
#include "render.h"
#include "player.h"
#include <stdlib.h>

#define KEY_W 0xD
#define KEY_A 0x0
#define KEY_S 0x1
#define KEY_D 0x2
#define KEY_ESC 0x35

t_map	*create_map(int argc, char *file)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nNo map file as parameter!\n", 2);
		return (NULL);
	}
	if (!is_valid_extension(file))
		return (NULL);
	map = parse_map(file);
	if (!map)
	{
		ft_putstr_fd("Error\nFailed to read the map file! (", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(")\n", 2);
		return (NULL);
	}
	map->n_collect = count_collects(map);
	if (!is_valid_map(map))
		return (NULL);
	return (map);
}

bool	load_sprites(t_game *game)
{
	char	*err;

	err = NULL;
	game->sprites[EMPTY] = new_sprite(game->mlx, "./assets/empty.xpm");
	if (!game->sprites[EMPTY])
		err = "Couldn't load file \"./assets/empty.xpm\"\n";
	game->sprites[WALL] = new_sprite(game->mlx, "./assets/wall.xpm");
	if (!game->sprites[WALL])
		err = "Couldn't load file \"./assets/wall.xpm\"\n";
	game->sprites[EXIT] = new_sprite(game->mlx, "./assets/exit.xpm");
	if (!game->sprites[EXIT])
		err = "Couldn't load file \"./assets/exit.xpm\"\n";
	game->sprites[PLAYER] = new_sprite(game->mlx, "./assets/player.xpm");
	if (!game->sprites[PLAYER])
		err = "Couldn't load file \"./assets/player.xpm\"\n";
	game->sprites[COLLECT] = new_sprite(game->mlx, "./assets/collectible.xpm");
	if (!game->sprites[PLAYER])
		err = "Couldn't load file \"./assets/collectible.xpm\"\n";
	if (err)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(err, 2);
		return (false);
	}
	return (true);
}

int	quit(t_game *game)
{
	free_game(game);
	exit(0);
}

int	keypress(int keycode, t_game *game)
{
	if (!game->done)
	{
		if (keycode == KEY_A)
			move_player(game, LEFT);
		else if (keycode == KEY_D)
			move_player(game, RIGHT);
		else if (keycode == KEY_W)
			move_player(game, UP);
		else if (keycode == KEY_S)
			move_player(game, DOWN);
	}
	if (game->state == PLAYING && game->done)
	{
		game->state = GAMEOVER;
		ft_putstr_fd("Victory! Score: ", 1);
		ft_putnbr_fd(game->player.moves, 1);
		ft_putchar_fd('\n', 1);
	}
	if (keycode == KEY_ESC)
		quit(game);
	draw_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	map = create_map(argc, argv[1]);
	if (!map)
		return (0);
	game = init_game(map);
	if (!game)
		return (0);
	if (!load_sprites(game))
	{
		free_game(game);
		return (0);
	}
	draw_game(game);
	mlx_hook(game->mlx_win, 2, 1, keypress, game);
	mlx_hook(game->mlx_win, 17, 0, quit, game);
	mlx_loop(game->mlx);
}
