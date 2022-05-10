/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiniz <ddiniz@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 22:32:15 by ddiniz            #+#    #+#             */
/*   Updated: 2022/05/09 21:47:22 by ddiniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NETX_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

#include <stddef.h>

size_t	ft_strlen(const char *str);
void	ft_cpylstr(const char *dest, const char *src, const size_t size);
char	*ft_joinstr(const char *dest, const char *src);
char	*get_next_line(int fd);

#endif
