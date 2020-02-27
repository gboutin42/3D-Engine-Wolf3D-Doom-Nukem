/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rectangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:16:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_rectangle	new_rectangle(t_vec2 p_pos, t_vec2 p_size)
{
	t_rectangle	result;

	result.pos = p_pos;
	result.size = p_size;
	return (result);
}

t_rectangle	*initialize_t_rectangle(t_vec2 p_pos, t_vec2 p_size)
{
	t_rectangle	*result;

	if (!(result = (t_rectangle *)ft_memalloc(sizeof(t_rectangle))))
		error_exit(-31, "Can't ft_memalloc a t_rectangle");
	*result = new_rectangle(p_pos, p_size);
	return (result);
}
