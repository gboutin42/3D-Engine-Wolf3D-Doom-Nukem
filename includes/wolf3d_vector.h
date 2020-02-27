/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_vector.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:58:44 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:58:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_VECTOR_H
# define WOLF3D_VECTOR_H

typedef struct	s_vec4
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vec4;

t_vec4			new_vec4(float p_x, float p_y, float p_z);
t_vec4			*initialize_t_vec4(float p_x, float p_y, float p_z);
t_vec4			add_vec4(t_vec4 a, t_vec4 b);
t_vec4			substract_vec4(t_vec4 a, t_vec4 b);
t_vec4			mult_2_vec4(t_vec4 a, t_vec4 b);
t_vec4			mult_vec4_by_float(t_vec4 a, float b);
t_vec4			divide_vec4_by_float(t_vec4 a, float b);
t_vec4			inv_t_vec4(t_vec4 src);
void			swap_t_vec4(t_vec4 *a, t_vec4 *b);
int				t_vec4_equal(t_vec4 a, t_vec4 b);

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
}				t_vector3;

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

t_vec2			create_vec2(float p_x, float p_y);
t_vec2			add_vector2_to_vector2(t_vec2 v1, t_vec2 v2);

typedef struct	s_vec2_int
{
	int			x;
	int			y;
}				t_vec2_int;

t_vec2_int		create_vec2_int(int p_x, int p_y);

#endif
