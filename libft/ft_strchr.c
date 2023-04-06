/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:24:27 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/03 20:26:39 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*int main()
{
    char str[] = "peppapig";
    char c = 'a';
    char *ptr;
    ptr = ft_strchr(str,c);
    printf("%s",ptr);
}*/
/*strchr returns a poiter to the first occurrence
of the character c in the string s*/
