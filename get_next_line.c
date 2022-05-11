/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:42:25 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/10 23:41:05 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE];
	static size_t	id_scan;
	static size_t	id_start;
	char			*line;
	char			*aux;

	line = "";
	aux = line;
	if (id_scan == 0 || id_scan >= BUFFER_SIZE - 1)
	{
		if (read(fd, buff, BUFFER_SIZE) == -1)
			return (NULL);
		id_scan = 0;
	}
	id_start = id_scan;
	if (buff[id_scan++] == '\n')
		return ("\n");
	while (id_scan < BUFFER_SIZE)
	{
		if (buff[id_scan] == '\n') //first char == '\n': ok; next char == '\n': ok
		{
			aux = (char *)malloc((id_scan - id_start + 2) * sizeof(char));
			ft_cpylstr(aux, &buff[id_start], (id_scan - id_start + 1));
			line = ft_joinstr(line, aux);
			free(aux);
			aux = NULL;
			id_scan++;
			break ;
		}
		else if (id_scan == BUFFER_SIZE - 1)
		{
			aux = (char *)malloc((id_scan - id_start + 2) * sizeof(char));
			ft_cpylstr(aux, &buff[id_start], (id_scan - id_start + 1));
			line = ft_joinstr(line, aux);
			free(aux);
			aux = NULL;
			read(fd, buff, BUFFER_SIZE);
			id_scan = 0;
		}
		else
			id_scan++;
	}
	return (line);
}
