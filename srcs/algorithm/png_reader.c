/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 14:32:25 by spuisais          #+#    #+#             */
/*   Updated: 2020/02/14 11:59:01 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			change_format(int color_type, t_surface *surface)
{
	if (color_type == PNG_COLOR_TYPE_RGB)
	{
		surface->format = GL_RGB;
		surface->intern_format = 3;
	}
	else if (color_type == PNG_COLOR_TYPE_RGB_ALPHA)
	{
		surface->format = GL_RGBA;
		surface->intern_format = 4;
	}
	else
		error_exit(0, "XXX");
}

void			set_row_pointers(t_surface *s, png_structp png_ptr)
{
	png_bytep		*row_pointers;
	unsigned int	i;

	if (!(s->pixels = (GLubyte *)ft_memalloc(sizeof(GLubyte) * s->w
						* s->h * s->intern_format)))
		error_exit(-8562, "error ft_memalloc pixel");
	row_pointers = (png_bytep *)ft_memalloc(sizeof(png_bytep) * s->h);
	i = 0;
	while (i < s->h)
	{
		row_pointers[i] = (png_bytep)(s->pixels + ((s->h - (i + 1)) * s->w
		* s->intern_format));
		i++;
	}
	png_read_image(png_ptr, row_pointers);
	ft_memdel((void**)&row_pointers);
}

t_surface		*read_png_file(FILE *fp)
{
	png_structp	png_ptr;
	png_infop	info_ptr;
	t_surface	*surface;
	int			bit_depth;
	int			color_type;

	if (!(surface = (t_surface *)ft_memalloc(sizeof(t_surface))))
		error_exit(-29, "Can't ft_memalloc a t_surface");
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);
	png_init_io(png_ptr, fp);
	png_read_info(png_ptr, info_ptr);
	bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);
	png_read_update_info(png_ptr, info_ptr);
	png_get_IHDR(png_ptr, info_ptr, (png_uint_32*)(&surface->w),
				(png_uint_32*)(&surface->h), &bit_depth, &color_type,
				NULL, NULL, NULL);
	change_format(color_type, surface);
	set_row_pointers(surface, png_ptr);
	png_read_end(png_ptr, NULL);
	png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
	fclose(fp);
	return (surface);
}

t_texture		*png_load(char *path)
{
	t_texture	*texture;
	FILE		*fp;

	if (!(texture = (t_texture *)ft_memalloc(sizeof(t_texture))))
		error_exit(-29, "Can't ft_memalloc a t_texture");
	if (!(texture->path = ft_strdup(path)))
		error_exit(-70, "ft_strdup failed");
	if ((fp = fopen(path, "rb")) == NULL)
		error_exit(-500, ft_strjoin(path, " doesn't exist"));
	texture->surface = read_png_file(fp);
	return (texture);
}
