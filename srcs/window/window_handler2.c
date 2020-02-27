/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:52:05 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:52:06 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		initialize_t_window3(t_window *win, int i)
{
	int			j;
	t_vector3	tmp_coord;
	t_color		tmp_color;

	tmp_color = new_color_from_int(255, 255, 255, 0);
	i = -1;
	while (++i < win->size_x)
	{
		j = -1;
		while (++j < win->size_y)
		{
			tmp_coord.x = i;
			tmp_coord.y = j;
			tmp_coord.z = 0.0f;
			win->vertex_data[i + j * win->size_x].x = tmp_coord.x \
										/ ((float)(win->size_x) / 2.0) - 1.0f;
			win->vertex_data[i + j * win->size_x].y = -(tmp_coord.y \
										/ ((float)(win->size_y) / 2.0) - 1.0f);
			win->vertex_data[i + j * win->size_x].z = tmp_coord.z;
		}
	}
	glBindVertexArray(win->vertex_array);
	glBindBuffer(GL_ARRAY_BUFFER, win->vertex_fixed_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * win->size_x * win->size_y \
										* 3, win->vertex_data, GL_STATIC_DRAW);
}

void		initialize_t_window2(t_window *win)
{
	int		i;

	i = -1;
	while (++i < NB_THREAD_MAX)
		win->data[i] = new_void_list();
	win->program_color = load_shaders("ressources/shader/color_shader.vert",
								"ressources/shader/color_shader.frag");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_ALWAYS);
	SDL_GL_SetSwapInterval(0);
	if (!(win->vertex_data = (t_vector3 *)ft_memalloc(sizeof(t_vector3) \
										* win->size_x * win->size_y)))
		error_exit(-456, "Can't ft_memalloc a t_vector3 array properly");
	if (!(win->color_data = (t_color *)ft_memalloc(sizeof(t_color) \
										* win->size_x * win->size_y)))
		error_exit(-456, "Can't ft_memalloc a t_color array properly");
	initialize_t_window3(win, i);
	glBindBuffer(GL_ARRAY_BUFFER, win->color_fixed_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * win->size_x * win->size_y \
										* 4, NULL, GL_DYNAMIC_DRAW);
}

t_window	*initialize_t_window(char *p_name, int p_size_x, int p_size_y)
{
	t_window	*win;

	if (!(win = (t_window *)ft_memalloc(sizeof(t_window))))
		error_exit(-6, "Can't ft_memalloc a t_window");
	if ((win->window = SDL_CreateWindow(p_name, 0, 0, p_size_x, p_size_y,
								SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)) == NULL)
		error_exit(ft_atoi(SDL_GetError()), "Erreur SDL_CreateWindow");
	SDL_GetWindowSize(win->window, &win->size_x, &win->size_y);
	win->context = SDL_GL_CreateContext(win->window);
	glGenVertexArrays(1, &win->vertex_array);
	glBindVertexArray(win->vertex_array);
	glGenBuffers(1, &win->vertex_buffer);
	glGenBuffers(1, &win->vertex_fixed_buffer);
	glGenBuffers(1, &win->color_buffer);
	glGenBuffers(1, &win->color_fixed_buffer);
	glGenBuffers(1, &win->texture_buffer);
	glGenBuffers(1, &win->alpha_buffer);
	initialize_t_window2(win);
	return (win);
}

void		delete_t_window(t_window dest)
{
	int	i;

	i = 0;
	ft_memdel((void**)&dest.color_data);
	ft_memdel((void**)&dest.vertex_data);
	while (i < NB_THREAD_MAX)
	{
		delete_t_void_list(dest.data[i]);
		i++;
	}
	SDL_DestroyWindow(dest.window);
}

void		free_t_window(t_window **dest)
{
	delete_t_window(**dest);
	ft_memdel((void**)dest);
}
