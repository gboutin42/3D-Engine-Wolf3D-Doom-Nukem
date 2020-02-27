/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector2_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:46 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:46 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec2_int	create_vec2_int(int p_x, int p_y)
{
	t_vec2_int	result;

	result.x = p_x;
	result.y = p_y;
	return (result);
}
