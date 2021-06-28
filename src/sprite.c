/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 23:10:17 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/28 15:52:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

t_sprite	*new_sprite(void *mlx, char *file)
{
	t_sprite	*sp;

	sp = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sp)
		return (NULL);
	sp->img = mlx_xpm_file_to_image(mlx, file, &sp->width, &sp->height);
	if (!sp->img)
		return (free_sprite(mlx, sp));
	sp->data = mlx_get_data_addr(sp->img, &sp->bpp, &sp->pitch, &sp->endian);
	sp->file = file;
	return (sp);
}

void	*free_sprite(void *mlx, t_sprite *sp)
{
	if (mlx && sp && sp->img)
		mlx_destroy_image(mlx, sp->img);
	free(sp);
	return (NULL);
}

int	get_pixel(t_sprite *sp, int x, int y)
{
	char	*pixel;

	pixel = sp->data + (y * sp->pitch + x * (sp->bpp / 8));
	return (*(int *)pixel);
}
