/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:42:25 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/08 20:45:45 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

static void	ft_strlcpy(const char *dest, const char *src, const size_t size)
{
	while (size > 0)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		size--;
	}
	*(char *)dest = '\0';
}

char	*ft_strjoin(const char *dest, const char *src)
{
	char	*join;
	char	*join_start;
	size_t	total_size;

	total_size = ft_strlen(dest) + ft_strlen(src) + 1;
	join = (char *)malloc(total_size * sizeof(char));
	if (!join)
		return (0);
	join_start = join;
	while (*dest)
	{
		*join = *(char *)dest;
		dest++;
		join++;
	}
	while (*src)
	{
		*join = *(char *)src;
		src++;
		join++;
	}
	*join = '\0';
	return (join_start);
}

void	ft_save_info(char *buff, size_t index, char *str, size_t len)
{
	char	*aux;

	aux = (char *)malloc((len + 2) * sizeof(char));
	ft_strlcpy(aux, buff[index], (len + 1));
	str = ft_strjoin(str, aux);
	free(aux);
	aux = NULL;
}

char	*get_next_line(int fd)
{
	// VAR DECLARATION
	static char		buff[BUFFER_SIZE];
	static size_t	id_scan;
	static size_t	id_start;
	static char		*str_line;

	if (id_scan == 0 || id_scan >= BUFFER_SIZE - 1)
	{
		read(fd, buff, BUFFER_SIZE);
		id_scan = 0;
	}
	id_start = id_scan;
	while (id_scan < BUFFER_SIZE)
	{
		if (buff[id_scan] == '\n' || buff[id_scan] == '\0')
		{
			ft_save_info(buff, id_start, str_line, (id_scan - id_start - 1));
			id_scan++;
			break;
		}
		else if (id_scan == BUFFER_SIZE - 1)
		{
			ft_save_info(buff, id_start, str_line, (id_scan - id_start));
			read(fd, buff, BUFFER_SIZE);
			id_scan = 0;
		}
		else
			id_scan++;
	}
	return (str_line);
}
