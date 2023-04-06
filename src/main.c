/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 19:38:52 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/04 20:16:39 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_win(t_all *p)
{
	int	x;
	int	y;

	x = p->win.x / 2;
	y = p->win.y / 2;
	mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
		p->pos.lux * SIZE, p->pos.luy * SIZE);
	mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.lwin,
		p->pos.ex * SIZE, p->pos.ey * SIZE);
	mlx_string_put(p->mlx, p->win.win, x * SIZE, y * SIZE,
		0x000000, "YOU WON!!");
	p->cont.check_loop = 1;
	ft_printf("\033[32m hai vinto!\n");
	ft_printf("\033[34m mosse:%d\n", p->cont.moves);
}

void	get_window(t_all *p)
{
	p->cont.check_loop = 0;
	p->mlx = mlx_init();
	mlx_do_key_autorepeaton(p->mlx);
	p->win.win = mlx_new_window(p->mlx,
			p->win.x * SIZE, p->win.y * SIZE, "comm_so_long");
	ft_images(p);
	p->cont.moves = 0;
	ft_printf("\033[33m GAME START!\n collect all the coins!]");
	ft_printf("\033[36m get to the exit without being caught by the enemies]");
	mlx_hook(p->win.win, 2, 1L << 0, &my_key_hook, p);
	mlx_hook(p->win.win, 17, 0, ft_close, p);
	mlx_string_put(p->mlx, p->win.win, 20, 55, 0x0000FF, "MOVES:");
	mlx_string_put(p->mlx, p->win.win, 20, 20, 0xFF0000, "couins to grab:");
	mlx_loop(p->mlx);
}

int	main(int argc, char **argv)
{
	char	*path;
	t_all	p;

	path = argv[1];
	if (argc == 2)
	{
		read_map(path, &p);
		get_window(&p);
	}
	else if (argc > 2)
		map_error("Error\n too many arguments!", &p, 0);
	else
		map_error("Error\n you need to choose a map as argument!", &p, 0);
	return (0);
}
