/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 23:03:29 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 23:34:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

typedef struct s_sprite
{
	void	*img;
	char	*file;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		pitch;
	int		endian;
}	t_sprite;

t_sprite	*new_sprite(void *mlx, char *file);
void		*free_sprite(void *mlx, t_sprite *sp);
int			get_pixel(t_sprite *sp, int x, int y);

#endif
