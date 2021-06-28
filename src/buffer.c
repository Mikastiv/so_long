/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:17:07 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/28 15:52:28 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

t_buffer	*new_buffer(void *mlx, int width, int height)
{
	t_buffer	*buf;

	buf = ft_calloc(1, sizeof(t_buffer));
	if (!buf)
		return (NULL);
	buf->img = mlx_new_image(mlx, width, height);
	if (!buf->img)
		return (free_buffer(mlx, buf));
	buf->data = mlx_get_data_addr(buf->img, &buf->bpp, &buf->pitch,
			&buf->endian);
	return (buf);
}

void	*free_buffer(void *mlx, t_buffer *buf)
{
	if (mlx && buf && buf->img)
		mlx_destroy_image(mlx, buf->img);
	free(buf);
	return (NULL);
}

void	swap_buffers(t_buffer **b1, t_buffer **b2)
{
	t_buffer	*tmp;

	tmp = *b1;
	*b1 = *b2;
	*b2 = tmp;
}

void	put_pixel(t_buffer *buf, int x, int y, int color)
{
	char	*pixel;

	pixel = buf->data + (y * buf->pitch + x * (buf->bpp / 8));
	*(int *)pixel = color;
}
