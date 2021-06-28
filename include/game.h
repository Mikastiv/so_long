/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 21:25:00 by mleblanc          #+#    #+#             */
/*   Updated: 2021/06/24 22:36:30 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "buffer.h"
# include "map.h"
# include "sprite.h"
# include "player.h"
# include <OpenGL/gl3.h>

# define SCALE 3
# define SP_SIZE 16
# define N_SPRITE 5

# define EMPTY 0
# define WALL 1
# define PLAYER 2
# define EXIT 3
# define COLLECT 4

typedef enum e_state
{
	PLAYING,
	GAMEOVER
}	t_state;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_buffer	*front;
	t_buffer	*back;
	t_map		*map;
	t_sprite	*sprites[N_SPRITE];
	t_player	player;
	bool		done;
	t_state		state;
}	t_game;

t_game	*init_game(t_map *map);
void	*free_game(t_game *game);
void	move_player(t_game *game, t_dir dir);

typedef struct s_mlx_img_list
{
	int						width;
	int						height;
	char					*buffer;
	GLfloat					vertexes[8];
	struct s_mlx_img_list	*next;
}	t_mlx_img_list;

typedef struct s_mlx_img_ctx
{
	GLuint					texture;
	GLuint					vbuffer;
	t_mlx_img_list			*img;
	struct s_mlx_img_ctx	*next;
}	t_mlx_img_ctx;

typedef struct s_mlx_win_list
{
	void					*winid;
	t_mlx_img_ctx			*img_list;
	int						nb_flush;
	int						pixmgt;
	struct s_mlx_win_list	*next;
}	t_mlx_win_list;

typedef struct s_mlx_ptr
{
	void			*appid;
	t_mlx_win_list	*win_list;
	t_mlx_img_list	*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	t_mlx_img_list	*font;
	int				main_loop_active;
}	t_mlx_ptr;

#endif
