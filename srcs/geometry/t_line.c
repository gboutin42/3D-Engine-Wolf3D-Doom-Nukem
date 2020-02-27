/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:27:35 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_line	new_line(t_vec4 p_a, t_vec4 p_b)
{
	t_line	result;

	result.a = p_a;
	result.b = p_b;
	return (result);
}

t_line	*initialize_t_line(t_vec4 p_a, t_vec4 p_b)
{
	t_line	*result;

	if (!(result = (t_line *)ft_memalloc(sizeof(t_line))))
		error_exit(-31, "Can't ft_memalloc a t_line");
	*result = new_line(p_a, p_b);
	return (result);
}

float	size_line(t_line line)
{
	float	result;
	float	power1;
	float	power2;
	float	power3;

	power1 = powf(line.a.x - line.b.x, 2.0);
	power2 = powf(line.a.y - line.b.y, 2.0);
	power3 = powf(line.a.z - line.b.z, 2.0);
	result = power1 + power2 + power3;
	return (fabs(sqrt(result)));
}
