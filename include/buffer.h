/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:59:45 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/26 23:23:38 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

typedef struct s_buffer
{
	void	*img;
	char	*data;
	int		bpp;
	int		pitch;
	int		endian;
}	t_buffer;

t_buffer	*new_buffer(void *mlx, int width, int height);
void		*free_buffer(void *mlx, t_buffer *buf);
void		swap_buffers(t_buffer **b1, t_buffer **b2);
void		put_pixel(t_buffer *buf, int x, int y, int color);

#endif
