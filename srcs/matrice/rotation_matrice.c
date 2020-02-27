/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:02:35 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_matrix	create_rotation_x_matrix(float angle)
{
	t_matrix	result;
	float		radian;

	result = new_matrix();
	radian = degree_to_radius(angle);
	result.value[1][1] = cos(radian);
	result.value[2][1] = -sin(radian);
	result.value[1][2] = sin(radian);
	result.value[2][2] = cos(radian);
	return (result);
}

t_matrix	create_rotation_y_matrix(float angle)
{
	t_matrix	result;
	float		radian;

	result = new_matrix();
	radian = degree_to_radius(angle);
	result.value[0][0] = cos(radian);
	result.value[0][2] = -sin(radian);
	result.value[2][0] = sin(radian);
	result.value[2][2] = cos(radian);
	return (result);
}

t_matrix	create_rotation_z_matrix(float angle)
{
	t_matrix	result;
	float		radian;

	result = new_matrix();
	radian = degree_to_radius(angle);
	result.value[0][0] = cos(radian);
	result.value[0][1] = sin(radian);
	result.value[1][0] = -sin(radian);
	result.value[1][1] = cos(radian);
	return (result);
}

t_matrix	create_rotation_matrix(float x, float y, float z)
{
	t_matrix	tmp[4];
	t_matrix	result;

	tmp[0] = create_rotation_x_matrix(x);
	tmp[1] = create_rotation_y_matrix(y);
	tmp[2] = create_rotation_z_matrix(z);
	tmp[3] = mult_matrix_by_matrix(tmp[0], tmp[1]);
	result = mult_matrix_by_matrix(tmp[3], tmp[2]);
	return (result);
}
