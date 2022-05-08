/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:42:25 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/07 23:23:07 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_verify_eol(char ch)
{
	if (ch == '\n' || ch == '\0')
		return (NULL);
}

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
	while (size > 1)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = '\0';
}

char	*ft_strjoin(const char *dest, const char *src)
{
	char	*join;
	char	*join_start;
	size_t	total_size;

	total_size = ft_strlen(dest) + ft_strlen(src) + 1;
	join = (char *)malloc(total_size * sizeof(char));
	join_start = join;
	if (!join)
		return (0);
	while (*dest)
	{
		*join = *dest;
		dest++;
		join++;
	}
	while (*src)
	{
		*join = *src;
		src++;
		join++;
	}
	*join = '\0';
	return (join_start);
}


char	*get_next_line(int fd)
{
	// VAR DECLARATION
	static char		buff[BUFFER_SIZE];
	static size_t	id_scan;
	static size_t	id_start;
	static char		*str_line;
	static char		*str_aux;

	//VERIFY SCANNING
	if (id_scan >= BUFFER_SIZE - 1 || buff == NULL)
	{
		read(fd, buff, BUFFER_SIZE);
		id_scan = 0;
	}

	// VERIFY END OF LINE OR FILE
	ft_verify_eol(buff[id_scan]);

	//BUILD LINE
	id_start = id_scan;
	while (id_scan < BUFFER_SIZE)
	{
		while (buff[id_scan] != '\n' && buff[id_scan] != '\0')
		{
			str_aux = (char *)malloc((id_scan - id_start + 1) * sizeof(char));
			ft_strlcpy(str_aux, buff[id_start], (id_scan - id_start + 1));
			str_line = ft_strjoin(str_line, str_aux);
			free(str_aux);
			str_aux = NULL;
			id_scan++;
		}
		read(fd, buff, BUFFER_SIZE);
		id_scan = 0;
	}

	//RETURN THE LINE
	return (str_line);
}
