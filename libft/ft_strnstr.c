/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:30:10 by adpassar          #+#    #+#             */
/*   Updated: 2022/10/17 16:33:12 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!*big && !*little) || !*little)
		return ((char *)big);
	if (!*big)
	{
		return (0);
	}
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)big + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
/*int main()
{
    char s1[] = "cammello";
    char s2[] = "mel";
    size_t len = 3;

    //printf("%d\n",strnstr(s1,s2,len));
    printf("%s\n",ft_strnstr(s1,s2,len));
}*/
