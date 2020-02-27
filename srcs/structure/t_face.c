/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_face.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:49 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:50 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_face	new_face(void)
{
	t_face	result;
	int		i;

	result.normale = new_vec4(0, 0, 0);
	i = -1;
	while (++i < 3)
	{
		result.color = new_color(1.0, 1.0, 1.0, 1.0);
		result.idx_verts[i] = -1;
		result.index_uvs[i] = -1;
	}
	return (result);
}

t_face	*initialize_t_face(void)
{
	t_face	*result;

	if (!(result = (t_face *)ft_memalloc(sizeof(t_face))))
		error_exit(-13, "Can't create a t_face");
	*result = new_face();
	return (result);
}

void	set_t_face_vertices(t_face *face, int a, int b, int c)
{
	face->idx_verts[0] = a;
	face->idx_verts[1] = b;
	face->idx_verts[2] = c;
}

void	set_t_face_uvs(t_face *face, int a, int b, int c)
{
	face->index_uvs[0] = a;
	face->index_uvs[1] = b;
	face->index_uvs[2] = c;
}

void	set_t_face_color(t_face *face, t_color color)
{
	face->color = color;
}
