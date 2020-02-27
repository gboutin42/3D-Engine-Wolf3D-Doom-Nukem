/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_texture.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:49:55 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:49:56 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color				get_pixel_color(t_texture *texture, int x, int y)
{
	int				i;
	unsigned char	info[4];
	int				pixel_index;
	t_color			result;

	if (x < 0 || (GLuint)x >= texture->surface->w ||
		y < 0 || (GLuint)y >= texture->surface->h)
		return (new_color(0.0, 0.0, 1.0, 1.0));
	pixel_index = (x + y * texture->surface->w) \
					* texture->surface->intern_format;
	i = -1;
	while (++i < 3)
		info[i] = texture->surface->pixels[pixel_index + i];
	if (texture->surface->intern_format == 4)
		info[3] = texture->surface->pixels[pixel_index + 3];
	else
		info[3] = 255;
	result = new_color_from_int((int)(info[0]), (int)(info[1]),
									(int)(info[2]), (int)(info[3]));
	return (result);
}
