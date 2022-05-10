/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:27:31 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/09 22:44:12 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_lenstr(const char *str)
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

void	ft_cpylstr(const char *dest, const char *src, size_t size)
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

char	*ft_joinstr(const char *dest, const char *src)
{
	char	*join;
	char	*join_start;
	size_t	total_size;

	total_size = ft_lenstr(dest) + ft_lenstr(src) + 1;
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
