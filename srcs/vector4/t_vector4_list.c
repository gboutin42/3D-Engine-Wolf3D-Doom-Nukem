/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector4_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:51:00 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:51:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec4_list		new_vec4_list(void)
{
	t_vec4_list list;

	if (!(list.vector = (t_vec4 *)ft_memalloc(sizeof(t_vec4) * PUSH_SIZE)))
		error_exit(-18, "Can't ft_memalloc a t_vec4 array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_vec4_list		*initialize_t_vec4_list(void)
{
	t_vec4_list *list;

	if (!(list = (t_vec4_list *)ft_memalloc(sizeof(t_vec4_list))))
		error_exit(-19, "Can't create a t_vec4_list array");
	*list = new_vec4_list();
	return (list);
}

void			t_vec4_list_push_back(t_vec4_list *dest, t_vec4 to_add)
{
	t_vec4	*tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->vector;
		if (!(dest->vector = (t_vec4 *)ft_memalloc(sizeof(t_vec4)
				* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_vec4 array");
		i = 0;
		while (i < dest->size)
		{
			dest->vector[i] = tmp[i];
			i++;
		}
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->vector[dest->size] = to_add;
	(dest->size)++;
}

void			t_vec4_list_add_back(t_vec4_list *dest, t_vec4 *to_add)
{
	t_vec4	*tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->vector;
		if (!(dest->vector = (t_vec4 *)ft_memalloc(sizeof(t_vec4)
			* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_vec4 array");
		i = 0;
		while (i < dest->size)
		{
			dest->vector[i] = tmp[i];
			i++;
		}
		ft_memdel((void**)tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->vector[dest->size].x = to_add->x;
	dest->vector[dest->size].y = to_add->y;
	dest->vector[dest->size].z = to_add->z;
	dest->vector[dest->size].w = to_add->w;
	(dest->size)++;
}
