/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:04:23 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/03 18:05:15 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	findchar(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	checkset(char *str, char *set)
{
	while (*str)
	{
		if (!findchar(*str, set))
			return (0);
		str++;
	}
	return (1);
}

/*int main ()
{
	char	*s1 = "00C0EE10101PEPPPPEEEEEE";
	char	*set = "01PCE";
	
	printf("%d\n", checkset(s1, set));
	return (0);
}*/
