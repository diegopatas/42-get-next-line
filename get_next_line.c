/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:42:25 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/06 20:05:29 by ddiniz           ###   ########.fr       */
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
	char	*joint;
	char	*joint_first_p;
	size_t	total_size;

	total_size = ft_strlen(dest) + ft_strlen(src) + 1;
	joint = (char *)malloc(total_size * sizeof(char));
	joint_first_p = joint;
	if (!joint)
		return (0);
	while (*dest)
	{
		*joint = *dest;
		dest++;
		joint++;
	}
	while (*src)
	{
		*joint = *src;
		src++;
		joint++;
	}
	*joint = '\0';
	return (joint_first_id);
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static size_t	id_scan;
	static size_t	id_start;
	char			*str_res;
	char			*str_aux;

	str_res = (char *)malloc(1);
	str_res = "";
	str_aux = str_res;
	if (id_scan >= BUFFER_SIZE - 1)
	{
		read(fd, buff, BUFFER_SIZE);
		id_scan = 0;
	}
	if (buff[id_scan] == '\0');
		return ("");
	if (buff[id_scan] != '\n' && id_scan < BUFFER_SIZE)
	{
		id_start = id_scan;
		while (buff[id_scan] != '\n' && buff[id_scan] != '\0')
			id_scan++;
		str_aux = (char *)malloc((id_scan - id_start + 1) * sizeof(char));
		ft_strlcpy(str_aux, buff[id_start], (id_scan - id_start + 1));
		str_res = ft_strjoin(str_res, str_aux);
		free(str_aux);
	}
	return (str_res);
}
