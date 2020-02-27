/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mesh_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:49:45 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/27 09:27:17 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mesh_list	new_mesh_list(void)
{
	t_mesh_list	list;

	if (!(list.mesh = (t_mesh *)ft_memalloc(sizeof(t_mesh) * PUSH_SIZE)))
		error_exit(-18, "Can't ft_memalloc a t_mesh array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_mesh_list	*initialize_t_mesh_list(void)
{
	t_mesh_list	*list;

	if (!(list = (t_mesh_list *)ft_memalloc(sizeof(t_mesh_list))))
		error_exit(-19, "Can't create a t_mesh_list array");
	*list = new_mesh_list();
	return (list);
}

void		t_mesh_list_push_back(t_mesh_list *dest, t_mesh to_add)
{
	t_mesh	*tmp;
	int		i;

	tmp = NULL;
	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->mesh;
		if (!(dest->mesh = (t_mesh *)ft_memalloc(sizeof(t_mesh)
											* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_mesh array");
		i = -1;
		while (++i < dest->size)
			dest->mesh[i] = tmp[i];
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->mesh[dest->size] = to_add;
	(dest->size)++;
}

void		delete_t_mesh_list(t_mesh_list *dest)
{
	int		i;

	i = 0;
	while (i < dest->size)
	{
		delete_t_mesh(t_mesh_list_get(dest, i));
		i++;
	}
	ft_memdel((void**)&dest->mesh);
}

void		free_t_mesh_list(t_mesh_list **dest)
{
	delete_t_mesh_list(*dest);
	ft_memdel((void**)dest);
}
