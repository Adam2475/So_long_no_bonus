/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:49:31 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/04 17:35:41 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <stddef.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# ifndef SIZE
#  define SIZE 50
# endif

typedef struct s_counter
{
	int		pos;
	int		exit;
	int		collect;
	int		moves;
	int		check_loop;
	char	*coll;
	char	*mov;
}	t_counter;

typedef struct s_window
{
	void	*win;
	int		x;
	int		y;
}	t_window;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*collectable;
	void	*exit;
}	t_img;

typedef struct s_sprite
{
	void	*player;
	void	*enemy;
	void	*lwin;
}	t_sprite;

typedef struct s_mat
{
	int	x;
	int	y;
}	t_mat;

typedef struct s_pos
{
	int	lux;
	int	luy;
	int	bex;
	int	bey;
	int	ex;
	int	ey;
}	t_pos;

typedef struct s_all
{
	void		*mlx;
	char		**matrix;
	char		**temp;
	char		*map;
	t_window	win;
	t_vector	lu;
	t_counter	cont;
	t_img		img;
	t_sprite	sprite;
	t_mat		mat;
	t_pos		pos;
}	t_all;

int		map_error(char *msg, t_all *p, int check);
void	get_window(t_all *p);
void	ft_string_to_win(t_all *p);
int		my_key_hook(int keycode, t_all *p);
int		ft_close(t_all *p);
void	read_map(char *path, t_all *p);
void	check_map(t_all *p);
int		contchar(t_all *p);
void	check_rows(t_all *p);
void	ft_find(char **temp, t_window size, t_vector pos);
void	ft_find_pos(t_all *p, char c);
void	ft_pos(t_all *p);
int		ft_flood_fill(char **tab, t_window size, t_vector pos);
void	ft_images(t_all *p);
void	ft_put_img(t_all *p, char c);
void	ft_charcheck(t_all *p);
int		free_mat(char **matrix);
int		move_right(t_all *p);
int		move_left(t_all *p);
int		move_down(t_all *p);
void	ft_win(t_all *p);
void	ft_collect(t_all *p);

#endif