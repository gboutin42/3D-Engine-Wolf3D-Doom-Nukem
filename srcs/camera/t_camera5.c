/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_camera5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:40:16 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		delete_t_view_port(t_view_port dest)
{
	ft_memdel((void**)&dest.depth_buffer);
}

void		free_t_view_port(t_view_port **dest)
{
	delete_t_view_port(**dest);
	ft_memdel((void**)dest);
}

void		delete_t_uv(t_uv dest)
{
	if (dest.texture != NULL)
		free_t_texture(&dest.texture);
}

void		free_t_uv(t_uv *dest)
{
	delete_t_uv(*dest);
}

void		delete_t_uv_list(t_uv_list dest)
{
	ft_memdel((void**)&dest.uvs);
}
