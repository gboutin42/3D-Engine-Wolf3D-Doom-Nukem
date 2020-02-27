/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rasterizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:24 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:24 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_rasterizer	new_rasterizer(t_vec4 a, t_vec4 b, t_vec4 c)
{
	t_rasterizer	result;

	result.a = (a.y - b.y);
	result.b = (b.x - a.x);
	result.c = (a.x * b.y) - (a.y * b.x);
	result.max = apply_formula(&result, c.x, c.y);
	return (result);
}

t_rasterizer	*initialize_t_rasterizer(t_vec4 a, t_vec4 b, t_vec4 c)
{
	t_rasterizer	*result;

	if (!(result = (t_rasterizer *)ft_memalloc(sizeof(t_rasterizer))))
		error_exit(-13, "Can't create a t_rasterizer");
	*result = new_rasterizer(a, b, c);
	return (result);
}

float			apply_formula(t_rasterizer *rast, float x, float y)
{
	return (rast->a * x + rast->b * y + rast->c);
}

float			calc_rasterizer(t_rasterizer *rast, float x, float y)
{
	return (apply_formula(rast, x, y) / rast->max);
}
