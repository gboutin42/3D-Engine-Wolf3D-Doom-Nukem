/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_uv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:07 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_uv	new_uv(t_triangle p_triangle, t_texture *p_texture)
{
	t_uv	result;

	result.texture = p_texture;
	result.uv = p_triangle;
	return (result);
}

t_uv	*initialize_t_uv(t_triangle p_triangle, t_texture *p_texture)
{
	t_uv	*result;

	if (!(result = (t_uv *)ft_memalloc(sizeof(t_uv))))
		return (NULL);
	*result = new_uv(p_triangle, p_texture);
	return (result);
}
