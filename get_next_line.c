/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:42:25 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/05 20:37:41 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*str_res;
	size_t	id;
	size_t	len;

	read(fd, (void *)buff, BUFFER_SIZE);
	len = 0;
	id = 0;
	while (buff[id] != '\n' && id < BUFFER_SIZE)
	{
		len++;
		id++;
	}
	str_res = (char *)malloc((len + 1) * sizeof(char));
	if (!str_res)
		return (0);
	id = 0;
	while (len)
	{
		str_res[id] = buff[id];
		id++;
		len--;
	}
	str_res[id] = '\0';
	return (str_res);
}
