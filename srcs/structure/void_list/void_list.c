/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:37 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:37 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		t_void_list_add_back(t_void_list *dest, int nb, ...)
{
	void	*to_add;
	int		i;
	va_list	params;

	va_start(params, nb);
	i = -1;
	while (++i < nb)
	{
		to_add = va_arg(params, void *);
		t_void_list_push_back(dest, to_add);
	}
	va_end(params);
}

void		t_void_list_push_back(t_void_list *dest, void *to_add)
{
	void	**tmp;
	int		i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->data;
		if (!(dest->data = (void **)ft_memalloc(sizeof(void *) \
							* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-17, "Can't realloc a void * array");
		i = -1;
		while (++i < dest->size)
			dest->data[i] = tmp[i];
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->data[dest->size] = to_add;
	dest->size++;
}

void		*t_void_list_at(t_void_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-23, "Segfault : t_void_list out of range");
	return (dest->data[index]);
}

void		**t_void_list_get(t_void_list *dest, int index)
{
	if (index < 0 || index >= dest->size)
		error_exit(-23, "Segfault : t_void_list out of range");
	return (&(dest->data[index]));
}
