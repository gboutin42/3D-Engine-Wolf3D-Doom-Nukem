/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_algorithm.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:38:29 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 14:38:33 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_ALGORITHM_H
# define WOLF3D_ALGORITHM_H

# include "wolf3d_mesh.h"

int		mesh_intersect(t_mesh *mesh_compared, t_mesh *mesh_target);
t_mesh	*cast_ray(t_engine *engine, t_vec4 pos, t_vec4 dir, char *shooter);

#endif
