/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:51:26 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:27 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec4		new_vec4(float p_x, float p_y, float p_z)
{
	t_vec4 result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	result.w = 1.0;
	return (result);
}

t_vec4		*initialize_t_vec4(float p_x, float p_y, float p_z)
{
	t_vec4 *result;

	if (!(result = (t_vec4 *)ft_memalloc(sizeof(t_vec4))))
		return (NULL);
	*result = new_vec4(p_x, p_y, p_z);
	return (result);
}

int			t_vec4_equal(t_vec4 a, t_vec4 b)
{
	if (a.x != b.x || a.y != b.y || a.z != b.z)
		return (BOOL_FALSE);
	return (BOOL_TRUE);
}

void		swap_t_vec4(t_vec4 *a, t_vec4 *b)
{
	t_vec4	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_vec4		inv_t_vec4(t_vec4 src)
{
	t_vec4	result;

	result.x = -1 * src.x;
	result.y = -1 * src.y;
	result.z = -1 * src.z;
	result.w = -1 * src.w;
	return (result);
}
