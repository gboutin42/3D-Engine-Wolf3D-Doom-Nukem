/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_t_camera_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:23:52 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_camera_list	new_camera_list(void)
{
	t_camera_list	list;

	if (!(list.camera = (t_camera *)ft_memalloc(sizeof(t_camera) * PUSH_SIZE)))
		error_exit(-18, "Can't ft_memalloc a t_camera array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_camera_list	*initialize_t_camera_list(void)
{
	t_camera_list	*list;

	if (!(list = (t_camera_list *)ft_memalloc(sizeof(t_camera_list))))
		error_exit(-19, "Can't create a t_camera_list array");
	*list = new_camera_list();
	return (list);
}

void			t_camera_list_push_back(t_camera_list *dest, t_camera to_add)
{
	t_camera	*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->camera;
		if (!(dest->camera = (t_camera *)ft_memalloc(sizeof(t_camera)
											* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_camera array");
		i = -1;
		while (++i < dest->size)
			dest->camera[i] = tmp[i];
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->camera[dest->size] = to_add;
	(dest->size)++;
}

void			t_camera_list_add_back(t_camera_list *dest, t_camera *to_add)
{
	t_camera	*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->camera;
		if (!(dest->camera = (t_camera *)ft_memalloc(sizeof(t_camera)
											* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-20, "Can't realloc a t_camera array");
		i = 0;
		while (i < dest->size)
		{
			dest->camera[i] = tmp[i];
			i++;
		}
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->camera[dest->size] = *to_add;
	(dest->size)++;
}
