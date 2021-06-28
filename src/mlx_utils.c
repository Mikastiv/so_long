/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:22:09 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/28 17:25:25 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <OpenGL/gl3.h>
#include <stdlib.h>
#include "mlx_int.h"

void	destroy_mlx(void *mlx)
{
	mlx_ptr_t	*ptr;

	ptr = (mlx_ptr_t *)mlx;
	if (ptr && ptr->font)
		mlx_destroy_image(mlx, ptr->font);
	free(mlx);
}
