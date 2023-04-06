/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpassar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:03:06 by adpassar          #+#    #+#             */
/*   Updated: 2023/04/04 17:03:56 by adpassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*delete(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

char	*read_from_fd(int fd, char *buff, char *str)
{
	int	n;

	n = 1;
	while (!ft_strchr(str, '\n') && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_return_line(char *str)
{
	int		i;
	char	*proxy_string;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		i++;
	}
	proxy_string = (char *)malloc((i + 2) * sizeof(*proxy_string));
	if (!proxy_string)
		return (NULL);
	i = -1;
	while (str[++i] != '\n' && str[i])
		proxy_string[i] = str[i];
	if (str[i] == '\n')
	{
		proxy_string[i] = '\n';
		i++;
	}
	proxy_string[i] = '\0';
	return (proxy_string);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*proxy_str;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buff));
	if (!buff)
		return (NULL);
	str = read_from_fd(fd, buff, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	proxy_str = get_return_line(str);
	str = delete(str);
	return (proxy_str);
}
