/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_triangle_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:27:46 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_triangle_list	new_triangle_list(void)
{
	t_triangle_list	list;

	if (!(list.triangle = (t_triangle *)ft_memalloc(sizeof(t_triangle)
																* PUSH_SIZE)))
		error_exit(-32, "Can't ft_memalloc a t_triangle array");
	list.size = 0;
	list.max_size = PUSH_SIZE;
	return (list);
}

t_triangle_list	*initialize_t_triangle_list(void)
{
	t_triangle_list	*list;

	if (!(list = (t_triangle_list *)ft_memalloc(sizeof(t_triangle_list))))
		error_exit(-33, "Can't create a t_triangle_list array");
	*list = new_triangle_list();
	return (list);
}

void			t_triangle_list_push_back(t_triangle_list *dest, t_triangle add)
{
	t_triangle	*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->triangle;
		if (!(dest->triangle = (t_triangle *)ft_memalloc(sizeof(t_triangle) \
										* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-34, "Can't realloc a t_triangle array");
		i = 0;
		while (i < dest->size)
		{
			dest->triangle[i] = tmp[i];
			i++;
		}
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->triangle[dest->size] = add;
	dest->size++;
}

void			t_triangle_list_add_back(t_triangle_list *dest, t_triangle *add)
{
	t_triangle	*tmp;
	int			i;

	if ((dest->size + 1) >= dest->max_size)
	{
		tmp = dest->triangle;
		if (!(dest->triangle = (t_triangle *)ft_memalloc(sizeof(t_triangle) \
										* (dest->size + 1 + PUSH_SIZE))))
			error_exit(-35, "Can't realloc a t_triangle array");
		i = 0;
		while (i < dest->size)
		{
			dest->triangle[i] = tmp[i];
			i++;
		}
		ft_memdel((void**)&tmp);
		dest->max_size += PUSH_SIZE;
	}
	dest->triangle[dest->size].a = add->a;
	dest->triangle[dest->size].b = add->b;
	dest->triangle[dest->size].c = add->c;
	dest->size++;
}

void			t_triangle_list_resize(t_triangle_list *dest, int new_size)
{
	t_triangle	*tmp;
	int			i;
	int			old_size;

	old_size = dest->size;
	tmp = dest->triangle;
	if (!(dest->triangle = (t_triangle *)ft_memalloc(sizeof(t_triangle) \
													* (new_size))))
		error_exit(-35, "Can't realloc a t_triangle array");
	i = 0;
	while (i < dest->size && i < new_size && i < old_size)
	{
		dest->triangle[i] = tmp[i];
		i++;
	}
	if (old_size != 0)
		ft_memdel((void**)&tmp);
	dest->max_size = new_size;
	dest->size = i;
}
