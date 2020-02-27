/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_uv_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:50:01 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:50:02 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_uv_list	new_uv_list(void)
{
	t_uv_list	result;

	if (!(result.uvs = (t_uv *)ft_memalloc(sizeof(t_uv) * PUSH_SIZE)))
		error_exit(-55, "Can't ft_memalloc uvs");
	result.size = 0;
	result.max_size = PUSH_SIZE;
	return (result);
}

t_uv_list	*initialize_t_uv_list(void)
{
	t_uv_list	*result;

	if (!(result = (t_uv_list *)ft_memalloc(sizeof(t_uv_list))))
		return (NULL);
	*result = new_uv_list();
	return (result);
}

void		t_uv_list_push_back(t_uv_list *dest, t_uv to_add)
{
	t_uv	*tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->uvs;
		if (!(dest->uvs = (t_uv *)ft_memalloc(sizeof(t_uv)
							* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-14, "Can't realloc a t_uv array");
		i = -1;
		while (++i < dest->size)
			dest->uvs[i] = tmp[i];
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->uvs[dest->size] = to_add;
	dest->size++;
}

t_uv		*t_uv_list_get(t_uv_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-28, "Segfault : t_color_list out of range");
	return (&dest->uvs[index]);
}

void		clean_t_uv_list(t_uv_list *dest)
{
	dest->size = 0;
}
