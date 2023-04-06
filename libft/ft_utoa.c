/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:59:16 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/03 19:25:01 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(unsigned int c)
{
	unsigned int		i;
	unsigned int		j;

	i = c;
	j = 0;
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	j++;
	return (j);
}

char	*ft_utoa(unsigned int c)
{
	int		i;
	char	a;
	char	*str;

	i = ft_count(c);
	str = malloc(i * 1);
	i = 0;
	while (c > 0)
	{
		a = (c % 10) + 48;
		c = c / 10;
		*(str + i) = a;
		i++;
	}
	*(str + i) = '\0';
	ft_rev_tab(str);
	return (str);
}
