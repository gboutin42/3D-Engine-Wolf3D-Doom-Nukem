/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_face_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:44 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:44 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_face_list	new_face_list(void)
{
	t_face_list	list;

	if (!(list.face = (t_face *)ft_memalloc(sizeof(t_face) * PUSH_SIZE)))
		error_exit(-25, "Can't ft_memalloc a t_face array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_face_list	*initialize_t_face_list(void)
{
	t_face_list	*list;

	if (!(list = (t_face_list *)ft_memalloc(sizeof(t_face_list))))
		error_exit(-26, "Can't create a t_face_list array");
	*list = new_face_list();
	return (list);
}

void		t_face_list_push_back(t_face_list *dest, t_face to_add)
{
	t_face	*tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->face;
		if (!(dest->face = (t_face *)ft_memalloc(sizeof(t_face) \
							* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-27, "Can't realloc a t_face array");
		i = -1;
		while (++i < dest->size)
			dest->face[i] = tmp[i];
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->face[dest->size] = to_add;
	dest->size++;
}

t_face		t_face_list_at(t_face_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-28, "Segfault : t_face_list out of range");
	return (dest->face[index]);
}

t_face		*t_face_list_get(t_face_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-28, "Segfault : t_face_list out of range");
	return (&dest->face[index]);
}
