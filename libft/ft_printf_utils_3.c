/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:03:43 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/03 19:24:32 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rev_tab(char *str)
{
	int		i;
	int		s;
	char	c;

	i = 0;
	s = 0;
	while (*(str + s) != '\0')
		s++;
	s = s - 1;
	while (i < (s - i))
	{
		c = *(str + i);
		*(str + i) = *(str + (s - i));
		*(str + (s - i)) = c;
		i++;
	}
	return ;
}

/* utoa utility */
int	ft_check_zero(unsigned int c)
{
	int	i;

	i = 0;
	if (c == 0)
	{
		i = i + ft_putchar(48);
		return (i);
	}
	return (0);
}
