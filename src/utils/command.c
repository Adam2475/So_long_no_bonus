/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:26:47 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/03 18:27:51 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_right(t_all *p)
{
	int	step;

	step = p->pos.lux;
	if (p->matrix[p->pos.luy][++step] == 'E' && p->cont.collect == 0)
		ft_win(p);
	else if (p->matrix[p->pos.luy][step] == 'B')
		ft_close(p);
	else if (p->matrix[p->pos.luy][step] != '1' &&
			p->matrix[p->pos.luy][step] != 'B' &&
			p->matrix[p->pos.luy][step] != 'E')
	{
		ft_string_to_win(p);
		p->pos.lux++;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			(p->pos.lux - 1) * SIZE, p->pos.luy * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.player,
			p->pos.lux * SIZE, p->pos.luy * SIZE);
		if (p->matrix[p->pos.luy][p->pos.lux] == 'C')
			ft_collect(p);
	}
	return (0);
}

int	move_left(t_all *p)
{
	int	step;

	step = p->pos.lux;
	if (p->matrix[p->pos.luy][--step] == 'E' && p->cont.collect == 0)
		ft_win(p);
	else if (p->matrix[p->pos.luy][step] == 'B')
		ft_close(p);
	else if (p->matrix[p->pos.luy][step] != '1' &&
			p->matrix[p->pos.luy][step] != 'B' &&
			p->matrix[p->pos.luy][step] != 'E')
	{
		ft_string_to_win(p);
		p->pos.lux--;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			(p->pos.lux + 1) * SIZE, p->pos.luy * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.player,
			p->pos.lux * SIZE, p->pos.luy * SIZE);
		if (p->matrix[p->pos.luy][p->pos.lux] == 'C')
			ft_collect(p);
	}
	return (0);
}

int	move_up(t_all *p)
{
	int	step;

	step = p->pos.luy;
	if (p->matrix[--step][p->pos.lux] == 'E' && p->cont.collect == 0)
		ft_win(p);
	else if (p->matrix[step][p->pos.lux] == 'B')
		ft_close(p);
	else if (p->matrix[step][p->pos.lux] != '1' &&
			p->matrix[step][p->pos.lux] != 'B' &&
			p->matrix[step][p->pos.lux] != 'E')
	{
		ft_string_to_win(p);
		p->pos.luy--;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			p->pos.lux * SIZE, (p->pos.luy + 1) * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.player,
			p->pos.lux * SIZE, p->pos.luy * SIZE);
		if (p->matrix[p->pos.luy][p->pos.lux] == 'C')
			ft_collect(p);
	}
	return (0);
}

int	move_down(t_all *p)
{
	int	step;

	step = p->pos.luy;
	if (p->matrix[++step][p->pos.lux] == 'E' && p->cont.collect == 0)
		ft_win(p);
	else if (p->matrix[step][p->pos.lux] == 'B')
		ft_close(p);
	else if (p->matrix[step][p->pos.lux] != '1' &&
		p->matrix[step][p->pos.lux] != 'B' &&
		p->matrix[step][p->pos.lux] != 'E')
	{
		ft_string_to_win(p);
		p->pos.luy++;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			p->pos.lux * SIZE, (p->pos.luy - 1) * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.player,
			p->pos.lux * SIZE, p->pos.luy * SIZE);
		if (p->matrix[p->pos.luy][p->pos.lux] == 'C')
			ft_collect(p);
	}
	return (0);
}

int	my_key_hook(int key, t_all *p)
{
	if (key == 65307)
		ft_close(p);
	if (p->cont.check_loop == 0)
	{
		if (key == 100 || key == 65363)
			move_right(p);
		else if (key == 97 || key == 65361)
			move_left(p);
		else if (key == 119 || key == 65362)
			move_up(p);
		else if (key == 115 || key == 65364)
			move_down(p);
	}
	return (0);
}
