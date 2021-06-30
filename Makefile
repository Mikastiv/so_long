NAME		= so_long

LIBMLX		= mlx
MLXDIR		= minilibx
MAKEMLX		= $(MAKE) -C $(MLXDIR)

LIBFT		= ft
FTDIR		= libft
MAKELIBFT	= $(MAKE) -C $(FTDIR)

INCDIR		= include
SRCDIR		= src
CFILES		= main.c map.c map_validation.c map_validation2.c map_validation3.c buffer.c\
			game.c sprite.c render.c map2.c player.c mlx_utils.c
HFILES		= map.h map_validation.h buffer.h game.h sprite.h render.h player.h mlx_utils.h
INCS		= $(addprefix $(INCDIR)/, $(HFILES))
SRCS		= $(addprefix $(SRCDIR)/, $(CFILES))
OBJS		= $(SRCS:.c=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf

%.o:		%.c
			$(CC) $(CFLAGS) -I$(FTDIR) -I$(MLXDIR) -I$(INCDIR) -c $< -o $@

$(NAME):	$(OBJS)
			$(MAKELIBFT)
			$(MAKEMLX)
			$(CC) $(CFLAGS) $(OBJS) -L$(FTDIR) -l$(LIBFT) -L$(MLXDIR) -l$(LIBMLX) -framework OpenGL -framework AppKit -o $(NAME)

all:		$(NAME)

clean:
			$(MAKELIBFT) clean
			$(MAKEMLX) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

norme:
			$(MAKELIBFT) norme
			norminette $(SRCS) $(INCS)

.PHONY:		all clean fclean re norme