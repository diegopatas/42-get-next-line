/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:42:25 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/04 22:24:40 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*buff[BUFFER_SIZE];
	char	*str_res;
	char	*str_aux;
	ssize_t	aux;

	aux = read(fd, buff, BUFFER_SIZE);
	str_res = (char *)malloc();
	while (buff[] != '\n' && buff[] != '\0')
	{
		len = ft_strlen(buff[]);
		str_aux = (char *)malloc((len + 1) * sizeof(char));
		ft_strlcpy(str_aux, buff, tamanho);

	}
}
