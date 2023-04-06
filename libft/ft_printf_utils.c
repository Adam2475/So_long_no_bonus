/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:30:50 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/03 19:24:35 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to print strings
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*(str + i) != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

//updated itoa to handle min and max of int
//created utoa for unsigned integers
//erased previous itoa from libft
int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_print_unsigned(unsigned int c)
{
	char	*str;
	int		i;

	i = ft_check_zero(c);
	if (i != 0)
		return (i);
	str = ft_utoa(c);
	i = ft_putstr(str);
	free(str);
	return (i);
}

/////////////////////////////////////////////////////////////////////////////

// print % sign
int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
