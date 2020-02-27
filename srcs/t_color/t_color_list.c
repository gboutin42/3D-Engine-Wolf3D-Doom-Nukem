/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:19 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:19 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color_list	new_color_list(void)
{
	t_color_list	list;

	if (!(list.color = (t_color *)ft_memalloc(sizeof(t_color) * PUSH_SIZE)))
		error_exit(-25, "Can't ft_memalloc a t_color array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_color_list	*initialize_t_color_list(void)
{
	t_color_list	*list;

	if (!(list = (t_color_list *)ft_memalloc(sizeof(t_color_list))))
		error_exit(-26, "Can't create a t_color_list array");
	*list = new_color_list();
	return (list);
}

void			t_color_list_push_back(t_color_list *dest, t_color to_add)
{
	t_color		*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->color;
		if (!(dest->color = (t_color *)ft_memalloc(sizeof(t_color) \
								* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-27, "Can't realloc a t_color array");
		i = -1;
		while (++i < dest->size)
			dest->color[i] = tmp[i];
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->color[dest->size] = to_add;
	dest->size++;
}

void			delete_t_color_list(t_color_list dest)
{
	ft_memdel((void**)&dest.color);
}

t_color			*t_color_list_get(t_color_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-28, "Segfault : t_color_list out of range");
	return (&dest->color[index]);
}
