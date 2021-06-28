/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:46:51 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 18:16:06 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "map.h"

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_dir;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

bool	is_valid_move(t_map *map, t_player *player, t_dir dir);
void	get_next_pos(t_player *player, t_dir dir, int *x, int *y);

#endif
