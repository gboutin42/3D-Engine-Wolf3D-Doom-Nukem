/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:59:53 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:59:53 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MATH_H
# define WOLF3D_MATH_H

# include "wolf3d_vector.h"
# include "wolf3d_basic_list.h"

typedef struct	s_matrix
{
	float		value[4][4];
}				t_matrix;

t_matrix		new_matrix();
t_matrix		*initialize_t_matrix();
t_matrix		new_matrix_empty();
t_matrix		new_translation_matrix(t_vec4 translation);
t_matrix		create_scaling_matrix(t_vec4 scaling);
t_matrix		create_rotation_x_matrix(float angle);
t_matrix		create_rotation_y_matrix(float angle);
t_matrix		create_rotation_z_matrix(float angle);
t_matrix		create_rotation_matrix(float x, float y, float z);
t_matrix		mult_matrix_by_matrix(t_matrix m1, t_matrix m2);
t_vec4			mult_vec4_by_matrix(t_vec4 vertex, t_matrix m);
void			print_t_matrix(t_matrix *m);

typedef struct	s_rasterizer
{
	float		a;
	float		b;
	float		c;
	float		max;
}				t_rasterizer;

t_rasterizer	new_rasterizer(t_vec4 s, t_vec4 e, t_vec4 ext);
t_rasterizer	*initialize_t_rasterizer(t_vec4 s, t_vec4 e, t_vec4 ext);
float			apply_formula(t_rasterizer *rast, float x, float y);
float			calc_rasterizer(t_rasterizer *rast, float x, float y);

char			*ft_itoa(int n);
int				generate_nbr(int min, int max);
t_vec4			cross_t_vec4(t_vec4 a, t_vec4 b);
t_vec4			normalize_t_vec4(t_vec4 v);
float			dot_t_vec4(t_vec4 a, t_vec4 b);
float			edge_t_vec4(t_vec4 a, t_vec4 b, t_vec4 c);
int				intersect_segment_by_segment(t_vec4 a, t_vec4 b,
											t_vec4 c, t_vec4 d);
t_vec4			inter_plane_line(t_vec4 p_normal, t_vec4 p_center,
								t_vec4 start, t_vec4 end);
int				intersect_triangle_by_segment(t_triangle p_triangle,
								t_line line, t_vec4 *intersection);

int				is_point_on_line(t_vec4 a, t_vec4 b, t_vec4 c);
float			dist_plane(t_vec4 p_normal, t_vec4 p_center, t_vec4 p_point);
float			clamp_float_value(float min, float value, float max);
float			calc_dist_vec4(t_vec4 a, t_vec4 b);
int				clamp_int_value(int min, int value, int max);
t_vec4			inter_vec4_line(float ratio_x, float ratio_y, t_vec4 ua,
								t_vec4 ub);
float			inter_ratio(float a, float b, float c);
int				get_short(int a, int b, int c);
int				get_big(int a, int b, int c);
float			get_short_float(float a, float b, float c);
float			get_big_float(float a, float b, float c);

int				is_triangle_cut_triangle(t_triangle p_a, t_triangle p_b);

int				old_intersect(t_triangle p_triangle, t_vec4 p_normal,
								t_line line, t_vec4 *intersection);
int				is_same_sign(float a, float b);
int				is_mid(float min, float max, float value);
float			signed_volume(t_vec4 a, t_vec4 b, t_vec4 c, t_vec4 d);

#endif
