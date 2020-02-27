/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_list2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:51:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:08 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			free_t_vec4_list(t_vec4_list **dest)
{
	delete_t_vec4_list(*dest);
	ft_memdel((void**)dest);
}

void			clean_t_vec4_list(t_vec4_list *dest)
{
	dest->size = 0;
}

t_vec4			t_vec4_list_at(t_vec4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vec4_list out of range");
	return (dest->vector[index]);
}

t_vec4			*t_vec4_list_get(t_vec4_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-24, "Segfault : t_vec4_list out of range");
	return (&dest->vector[index]);
}
