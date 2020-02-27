/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_gui.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:58:51 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_gui	new_gui(void)
{
	t_gui	res;
	int		idx;

	if (!(res.letter = (t_letter **)ft_memalloc(sizeof(t_letter*) * 94)))
		error_exit(-29, "Can't ft_memalloc a t_surface");
	if (!(res.menu = (t_texture **)ft_memalloc(sizeof(t_texture*) * 20)))
		error_exit(-29, "Can't ft_memalloc a t_surface");
	idx = -1;
	while (++idx < 94)
	{
		if (!(res.letter[idx] = (t_letter *)ft_memalloc(sizeof(t_letter))))
			error_exit(-29, "Can't ft_memalloc a t_surface");
		if (!(res.letter[idx]->let = (t_texture *)ft_memalloc(
															sizeof(t_texture))))
			error_exit(-29, "Can't ft_memalloc a t_surface");
		if (!(res.letter[idx]->let->surface =\
								(t_surface *)ft_memalloc(sizeof(t_surface))))
			error_exit(-29, "Can't ft_memalloc a t_surface");
	}
	res.idx = 8;
	res.sens = 2;
	res.key_press = 0;
	res.info_print = 0;
	return (res);
}

t_gui	*initialize_t_gui(void)
{
	t_gui	*result;

	if (!(result = (t_gui *)ft_memalloc(sizeof(t_gui))))
		error_exit(-13, "Can't create a t_gui");
	*result = new_gui();
	return (result);
}

void	set_t_gui_texte(t_gui *gui)
{
	int		i;
	char	letter[2];

	i = 0;
	letter[0] = ' ';
	letter[1] = '\0';
	while (i < 94)
	{
		load_letter(gui, letter, i);
		i++;
		letter[0]++;
	}
}

void	print_letter(t_camera *main_cam, t_gui *gui, char *str, t_rectangle rec)
{
	int		i;
	int		idx;
	int		len;

	i = -1;
	len = ft_strlen(str);
	t_view_port_clear_buffers(main_cam->view_port);
	while (++i < len)
	{
		idx = -1;
		while (++idx <= 94)
		{
			if (str[i] == gui->letter[idx]->let->letter)
			{
				draw_rectangle_texture_cpu(main_cam->view_port, rec,
											gui->letter[idx]->let);
				rec.pos = add_vector2_to_vector2(rec.pos,
											create_vec2(rec.size.x, 0.0));
				break ;
			}
		}
	}
}

void	print_info_bar(t_camera *main_camera, t_player *player, t_gui *gui)
{
	char	*str;
	t_vec2	size;

	size = create_vec2(0.02, 0.07);
	str = ft_itoa(player->armor);
	print_letter(main_camera, gui, str,
		new_rectangle(create_vec2(-0.70, -0.87), size));
	ft_memdel((void**)&str);
	str = ft_itoa(player->hp);
	print_letter(main_camera, gui, str,
		new_rectangle(create_vec2(-0.70, -0.97), size));
	ft_memdel((void**)&str);
	if (player->current_weapon->index != 5)
	{
		str = ft_itoa(player->current_weapon->ammo);
		str = ft_strjoinf(str, " / ", 1);
		str = ft_strjoinf(str, ft_itoa(player->current_weapon->total_ammo), 3);
		print_letter(main_camera, gui, str,
					new_rectangle(create_vec2(0.78, -0.90),
										create_vec2(0.01, 0.05)));
		ft_memdel((void**)&str);
	}
}
