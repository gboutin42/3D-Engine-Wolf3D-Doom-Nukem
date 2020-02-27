/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:58:08 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mesh		t_mesh_list_at(t_mesh_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_mesh_list out of range");
	return (dest->mesh[index]);
}

t_mesh		*t_mesh_list_get(t_mesh_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_mesh_list out of range");
	return (&(dest->mesh[index]));
}
