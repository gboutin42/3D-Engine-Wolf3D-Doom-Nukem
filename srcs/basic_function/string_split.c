/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:44:21 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:44:22 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		*ft_strncpy_end(char *dst, char const *src, size_t len)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	dst[i] = 0;
	return (dst);
}

static int		ft_is_sep(char const str, char c)
{
	if (str == c && str != '\0')
		return (1);
	return (0);
}

static int		ft_count_word(char const *str, char c)
{
	int			i;
	int			word;

	i = 0;
	word = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		while (!(str[i] == c) && str[i] != '\0')
			i++;
		while ((str[i] == c) && str[i] != '\0')
			i++;
		word++;
	}
	return (word);
}

static int		ft_let(char const *str, char c)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			i++;
			size++;
			if (str[i] == c)
				return (size);
		}
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			len;

	i = -1;
	len = ft_count_word(s, c);
	if (s == NULL)
		error_exit(-8, "ft_strsplit, premier malloc");
	while (ft_is_sep(*s, c))
		s++;
	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (len + 1))))
		error_exit(-8, "ft_strsplit, premier malloc");
	while (++i < len)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char*) * (ft_let(s, c) + 1))))
			ft_freetab(&tab);
		if (!tab)
			error_exit(-8, "ft_strsplit, premier malloc");
		ft_strncpy_end(tab[i], s, ft_let(s, c));
		s += ft_let(s, c);
		while (ft_is_sep(*s, c))
			++s;
	}
	tab[i] = NULL;
	return (tab);
}
