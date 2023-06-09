/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:15:34 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/04 17:51:21 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "../so_long.h"

int	contchar(t_all *p)
{
	int	i;
	int	pos;
	int	e;

	pos = 0;
	e = 0;
	p->cont.collect = 0;
	i = 0;
	while (p->map[i])
	{
		if (p->map[i] == 'P')
			pos++;
		if (p->map[i] == 'E')
			e++;
		if (p->map[i] == 'C')
			p->cont.collect++;
		i++;
	}
	if (pos > 0 && e == 1 && p->cont.collect >= 1)
		return (1);
	return (0);
}

void	check_rows(t_all *p)
{
	int	i;
	int	len;
	int	row;

	i = 0;
	len = p->win.x;
	row = p->win.y;
	while (i < p->win.y)
	{
		if ((int)ft_strlen(p->matrix[i]) != len)
			map_error("Error\n oh no! the map must be rectangular!", p, 3);
		if (p->matrix[i][0] != '1' || p->matrix[i][len - 1] != '1')
			map_error("Error\n oh no! some error in the wall", p, 3);
		i++;
	}
	i = 0;
	while (p->matrix[0][i] && p->matrix[row - 1][i])
	{
		if (p->matrix[0][i] != '1' || p->matrix[row - 1][i] != '1')
			map_error("Error\n oh no! some error in the wall", p, 3);
		i++;
	}
}

void	check_map(t_all *p)
{
	p->temp = NULL;
	if (!checkset(p->map, "01PECB\n"))
		map_error("Error\n there are not allowed characters in the map", p, 1);
	if (!contchar(p))
		map_error("Error\n the map must have at least 1E, 1P & 1C!", p, 1);
	p->matrix = ft_split(p->map, '\n');
	p->temp = ft_split(p->map, '\n');
	p->win.x = ft_strlen(p->matrix[0]);
	free(p->map);
	if (p->win.x == p->win.y)
		map_error("Error\n the map must be rectangular!", p, 3);
	check_rows(p);
	ft_pos(p);
	p->lu.x = p->pos.lux;
	p->lu.y = p->pos.luy;
	if (ft_flood_fill(p->temp, p->win, p->lu))
	{
		free_mat(p->temp);
		map_error("Error\n the E/C are not reachable", p, 2);
	}
	free_mat(p->temp);
}

void	read_map(char *path, t_all *p)
{
	char	*line;
	int		fd;

	p->win.y = 1;
	p->map = ft_calloc(1, 1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		map_error("Error\n problem with the map path", p, 1);
	}
	line = get_next_line(fd);
	while (line)
	{
		p->map = ft_strjoin(p->map, line);
		free(line);
		line = get_next_line(fd);
		if (line)
			p->win.y++;
	}
	close(fd);
	free(line);
	check_map(p);
}
