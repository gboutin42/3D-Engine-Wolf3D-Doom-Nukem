/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_t_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 12:24:59 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_t_surface(t_surface dest)
{
	ft_memdel((void**)&dest.pixels);
}

void	free_t_surface(t_surface **dest)
{
	delete_t_surface(**dest);
	ft_memdel((void**)dest);
}

void	delete_t_texture(t_texture *dest)
{
	if (dest->surface != NULL)
		free_t_surface(&dest->surface);
	ft_strdel(&dest->path);
}

void	free_t_texture(t_texture **dest)
{
	delete_t_texture(*dest);
	ft_memdel((void**)dest);
}
