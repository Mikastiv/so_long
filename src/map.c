/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:39:26 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 16:51:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map && map->grid)
	{
		while (i < map->height)
			free(map->grid[i++]);
		free(map->grid);
	}
	if (map)
		free(map);
}

static void	append_line(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (i < map->height && map->grid[i])
		++i;
	if (i < map->height)
		map->grid[i] = line;
	if (i == 0)
		map->width = (int)ft_strlen(line);
}

static t_map	*new_map(char *file)
{
	t_map	*map;
	int		n_lines;

	n_lines = count_lines(file);
	if (n_lines == -1)
		return (NULL);
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = n_lines;
	map->grid = (char **)ft_calloc((size_t)n_lines, sizeof(char *));
	if (!map->grid)
		return (ft_free((void **)&map));
	return (map);
}

t_map	*parse_map(char *file)
{
	int		fd;
	int		code;
	char	*line;
	t_map	*map;

	map = new_map(file);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_free((void **)&map));
	code = 1;
	while (code > 0)
	{
		code = get_next_line(fd, &line);
		if (code == -1)
		{
			close(fd);
			free_map(map);
			return (NULL);
		}
		append_line(map, line);
	}
	return (map);
}

void	get_player_pos(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->grid[j][i] == PLAYER_C)
			{
				*x = i;
				*y = j;
			}
			++i;
		}
		++j;
	}
}
