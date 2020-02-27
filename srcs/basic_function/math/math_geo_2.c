/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_geo_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:19:19 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float	signed_volume(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d)
{
	t_vec4	sub_res1;
	t_vec4	sub_res2;
	t_vec4	sub_res3;

	sub_res1 = substract_vec4(b, a);
	sub_res2 = substract_vec4(c, a);
	sub_res3 = substract_vec4(d, a);
	return ((1.0 / 6.0) * dot_t_vec4(cross_t_vec4(sub_res1, sub_res2),
																	sub_res3));
}
