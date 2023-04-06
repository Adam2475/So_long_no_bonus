/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:47:12 by iragusa           #+#    #+#             */
/*   Updated: 2023/04/03 18:25:15 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_mat(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	return (0);
}

int	map_error(char *msg, t_all *p, int check)
{
	if (check == 1)
		free(p->map);
	if (check == 2)
		free_mat(p->matrix);
	if (check == 3)
	{
		free_mat(p->matrix);
		free_mat(p->temp);
	}	
	perror(msg);
	exit (0);
}

int	ft_close(t_all *p)
{
	mlx_destroy_image(p->mlx, p->img.floor);
	mlx_destroy_image(p->mlx, p->img.wall);
	mlx_destroy_image(p->mlx, p->sprite.player);
	mlx_destroy_image(p->mlx, p->sprite.lwin);
	mlx_destroy_image(p->mlx, p->img.collectable);
	mlx_destroy_image(p->mlx, p->img.exit);
	mlx_destroy_image(p->mlx, p->sprite.enemy);
	mlx_clear_window(p->mlx, p->win.win);
	mlx_destroy_window(p->mlx, p->win.win);
	mlx_destroy_display(p->mlx);
	free_mat(p->matrix);
	free(p->mlx);
	exit(0);
}
