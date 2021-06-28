/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:31:44 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/27 16:14:46 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include "map.h"
# include <stdbool.h>

bool	is_valid_extension(char *file);
bool	is_closed(t_map *map);
bool	is_rect(t_map *map);
bool	has_exit(t_map *map);
bool	has_one_start(t_map *map);
bool	has_collectible(t_map *map);
bool	has_only_valid_chars(t_map *map);
bool	is_valid_map(t_map *map);

#endif
