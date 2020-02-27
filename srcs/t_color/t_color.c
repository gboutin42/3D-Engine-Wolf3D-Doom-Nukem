/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:24 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:25 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color	new_color(float p_r, float p_g, float p_b, float p_a)
{
	t_color	color;

	color.r = p_r;
	color.g = p_g;
	color.b = p_b;
	color.a = p_a;
	return (color);
}

t_color	*initialize_t_color(float p_r, float p_g, float p_b, float p_a)
{
	t_color	*color;

	if (!(color = (t_color *)ft_memalloc(sizeof(t_color))))
		return (NULL);
	*color = new_color(p_r, p_g, p_b, p_a);
	return (color);
}

t_color	new_color_from_int(int p_r, int p_g, int p_b, int p_a)
{
	t_color	color;

	color = new_color((float)(p_r) / 255.0f, (float)(p_g) / 255.0f,
							(float)(p_b) / 255.0f, (float)(p_a) / 255.0f);
	return (color);
}

t_color	fuze_t_color(t_color src1, t_color src2)
{
	t_color	result;
	float	base_alpha;
	float	inv_alpha;

	base_alpha = src2.a;
	inv_alpha = 1 - base_alpha;
	result.r = src2.r * base_alpha + inv_alpha * src1.r;
	result.g = src2.g * base_alpha + inv_alpha * src1.g;
	result.b = src2.b * base_alpha + inv_alpha * src1.b;
	if (src1.a == 1)
		result.a = 1.0f;
	else
		result.a = src2.a * base_alpha + inv_alpha * src1.a;
	return (result);
}
