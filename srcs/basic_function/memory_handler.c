/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:43:53 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/27 10:23:33 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_bzero(void *src, size_t nb_bytes)
{
	char	*p_src;
	size_t	i;

	i = 0;
	p_src = src;
	while (nb_bytes > i)
	{
		p_src[i] = 0;
		i++;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
	}
	return (dst);
}
