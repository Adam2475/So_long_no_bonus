/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:20:23 by adpassar          #+#    #+#             */
/*   Updated: 2022/10/10 17:21:08 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c)) != 0 || (ft_isdigit(c)) != 0)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
/*int main()
{
    char c = 'b';
    printf("%d", ft_isalnum(c));
    return 0;
}*/
