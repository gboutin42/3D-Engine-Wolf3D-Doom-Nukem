/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:53 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec2	create_vec2(float p_x, float p_y)
{
	t_vec2	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}

t_vec2	add_vector2_to_vector2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	result;

	result = create_vec2(v1.x + v2.x, v1.y + v2.y);
	return (result);
}
