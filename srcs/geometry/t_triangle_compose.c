/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle_compose.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:29:33 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_triangle	compose_t_triangle_from_t_mesh(t_mesh *src, int *index)
{
	t_triangle	result;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (src->vertices->size <= index[i])
			error_exit(-14, "can't compose a triangle");
		i++;
	}
	result.a = add_vec4(t_vec4_list_at(src->vertices,
														index[0]), src->pos);
	result.b = add_vec4(t_vec4_list_at(src->vertices,
														index[1]), src->pos);
	result.c = add_vec4(t_vec4_list_at(src->vertices,
														index[2]), src->pos);
	return (result);
}

t_triangle	compose_t_triangle_from_t_vertices(t_vec4_list *src, int *index)
{
	t_triangle	result;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (src->size <= index[i])
			error_exit(-14, "can't compose a triangle");
		i++;
	}
	result.a = t_vec4_list_at(src, index[0]);
	result.b = t_vec4_list_at(src, index[1]);
	result.c = t_vec4_list_at(src, index[2]);
	return (result);
}
