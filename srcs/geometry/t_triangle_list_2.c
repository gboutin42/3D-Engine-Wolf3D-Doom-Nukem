/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle_list_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:23:47 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			delete_t_triangle_list(t_triangle_list dest)
{
	ft_memdel((void**)&dest.triangle);
}

void			free_t_triangle_list(t_triangle_list **dest)
{
	delete_t_triangle_list(**dest);
	ft_memdel((void**)dest);
}

void			clean_t_triangle_list(t_triangle_list *dest)
{
	dest->size = 0;
}

t_triangle		t_triangle_list_at(t_triangle_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-36, "Segfault : t_triangle_list out of range");
	return (dest->triangle[index]);
}

t_triangle		*t_triangle_list_get(t_triangle_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-36, "Segfault : t_triangle_list out of range");
	return (&dest->triangle[index]);
}
