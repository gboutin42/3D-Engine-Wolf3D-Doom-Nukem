/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread_draw_color_cpu.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:15:48 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	thread_draw_color_cpu_next(t_void_list *data, int i, int start,
																	int len)
{
	t_view_port		*view_port;
	t_triangle_list	*triangle_list;
	t_color_list	*color_list;
	t_triangle		*triangle;
	t_color			*color;

	view_port = (t_view_port *)(t_void_list_at(data, 2));
	triangle_list = (t_triangle_list *)(t_void_list_at(data, 3));
	color_list = (t_color_list *)(t_void_list_at(data, 4));
	while (i < len && (start + i) < triangle_list->size)
	{
		triangle = t_triangle_list_get(triangle_list, start + i);
		color = t_color_list_get(color_list, start + i);
		draw_triangle_color_cpu(view_port, triangle, color);
		i++;
	}
}

void		*thread_draw_color_cpu(void *void_list)
{
	t_void_list		*data;
	int				i;
	int				start;
	int				len;

	i = 0;
	data = (t_void_list *)(void_list);
	start = (int)(t_void_list_at(data, 0));
	len = (int)(t_void_list_at(data, 1));
	thread_draw_color_cpu_next(data, i, start, len);
	pthread_exit(NULL);
}

void		multithreading_draw_triangle_color_cpu(t_view_port *p_view_port,
				t_triangle_list *p_triangle_list, t_color_list *p_color_list)
{
	int	tab[5];

	tab[0] = 0;
	tab[1] = p_triangle_list->size % NB_THREAD_MAX;
	tab[3] = -1;
	tab[4] = p_triangle_list->size / (NB_TRIANGLE_MAX);
	if (tab[4] == 0)
		tab[4]++;
	if (tab[4] >= NB_THREAD_MAX)
		tab[4] = NB_THREAD_MAX;
	while (++tab[3] < tab[4])
	{
		tab[2] = p_triangle_list->size / tab[4];
		if (tab[3] < tab[1])
			tab[2]++;
		clean_t_void_list(&(p_view_port->window->data[tab[3]]));
		t_void_list_add_back(&p_view_port->window->data[tab[3]], 5,
		(long)tab[0], (long)tab[2], p_view_port, p_triangle_list, p_color_list);
		pthread_create(&(p_view_port->window->threads[tab[3]]), NULL,
				thread_draw_color_cpu, &(p_view_port->window->data[tab[3]]));
		tab[0] += tab[2];
	}
	tab[3] = -1;
	while (++tab[3] < tab[4])
		pthread_join(p_view_port->window->threads[tab[3]], NULL);
}
