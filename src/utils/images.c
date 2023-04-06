/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:47:36 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/04 17:53:46 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// in this file we will associate the graphic resources to
// the variables in the struct

#include "../so_long.h"

void	ft_collect(t_all *p)
{
	p->cont.coll = ft_itoa(p->cont.collect);
	p->matrix[p->pos.luy][p->pos.lux] = '0';
	mlx_string_put(p->mlx, p->win.win, 120, 20, 0x006400,
		p->cont.coll);
	free(p->cont.coll);
	p->cont.collect--;
	ft_string_to_win(p);
}

void	ft_string_to_win(t_all *p)
{
	p->cont.mov = ft_itoa(p->cont.moves);
	mlx_string_put(p->mlx, p->win.win, 60, 55, 0xFFFFFF, p->cont.mov);
	p->cont.moves++;
	free(p->cont.mov);
	p->cont.mov = ft_itoa(p->cont.moves);
	p->cont.coll = ft_itoa(p->cont.collect);
	mlx_string_put(p->mlx, p->win.win, 60, 55, 0xFF00FF, p->cont.mov);
	mlx_string_put(p->mlx, p->win.win, 120, 20, 0xFF0000, p->cont.coll);
	if (p->cont.collect == 0)
	{
		mlx_string_put(p->mlx, p->win.win, 120, 20, 0x006400, p->cont.coll);
		mlx_string_put(p->mlx, p->win.win, 120, 20, 0xFFFF00,
			"reach the exit!!");
	}
	free(p->cont.mov);
	free (p->cont.coll);
}

void	ft_images(t_all *p)
{
	static int	hw = 5;

	p->img.floor = mlx_xpm_file_to_image(p->mlx, "src/imgs/free.xpm", &hw, &hw);
	p->img.wall = mlx_xpm_file_to_image(p->mlx, "src/imgs/wall.xpm", &hw, &hw);
	p->img.collectable
		= mlx_xpm_file_to_image(p->mlx, "src/imgs/gold.xpm", &hw, &hw);
	p->img.exit = mlx_xpm_file_to_image(p->mlx, "src/imgs/exit.xpm", &hw, &hw);
	p->sprite.player
		= mlx_xpm_file_to_image(p->mlx, "src/imgs/me.xpm", &hw, &hw);
	p->sprite.enemy
		= mlx_xpm_file_to_image(p->mlx, "src/imgs/gh.xpm", &hw, &hw);
	ft_charcheck(p);
}

void	ft_put_img(t_all *p, char c)
{
	if (c == '0')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == '1')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.wall,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.player,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.collectable,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.exit,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'B')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.enemy,
			p->mat.x * SIZE, p->mat.y * SIZE);
}

void	ft_charcheck(t_all *p)
{
	p->mat.y = 0;
	while (p->mat.y < p->win.y)
	{
		p->mat.x = 0;
		while (p->matrix[p->mat.y][p->mat.x] != '\0')
		{
			ft_put_img(p, p->matrix[p->mat.y][p->mat.x]);
			p->mat.x++;
		}
		p->mat.y++;
	}
}
