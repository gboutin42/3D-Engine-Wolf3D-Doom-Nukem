/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:04:53 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_matrix	mult_matrix_by_matrix(t_matrix m1, t_matrix m2)
{
	t_matrix	result;
	int			i;
	int			j;

	result = new_matrix_empty();
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			result.value[j][i] = (m1.value[0][i] * m2.value[j][0]) \
								+ (m1.value[1][i] * m2.value[j][1]) \
								+ (m1.value[2][i] * m2.value[j][2]) \
								+ (m1.value[3][i] * m2.value[j][3]);
	}
	return (result);
}

t_vec4		mult_vec4_by_matrix(t_vec4 vertex, t_matrix m)
{
	float	result[3];

	result[0] = m.value[0][0] * vertex.x + m.value[1][0] * vertex.y \
							+ m.value[2][0] * vertex.z + m.value[3][0];
	result[1] = m.value[0][1] * vertex.x + m.value[1][1] * vertex.y \
							+ m.value[2][1] * vertex.z + m.value[3][1];
	result[2] = m.value[0][2] * vertex.x + m.value[1][2] * vertex.y \
							+ m.value[2][2] * vertex.z + m.value[3][2];
	return (new_vec4(result[0], result[1], result[2]));
}
