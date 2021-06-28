/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:01:37 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 16:48:31 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define EMPTY_C '0'
# define WALL_C '1'
# define COLLECT_C 'C'
# define EXIT_C 'E'
# define PLAYER_C 'P'

# include "libft.h"

typedef struct s_map
{
	char	**grid;
	int		height;
	int		width;
	int		n_collect;
}	t_map;

t_map	*parse_map(char *file);
void	free_map(t_map *map);
int		count_collects(t_map *map);
void	get_player_pos(t_map *map, int *x, int *y);

#endif
