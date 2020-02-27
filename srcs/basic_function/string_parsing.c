/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:44:07 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:44:09 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char		*ft_strcut(char **src, char delim)
{
	char	*tmp;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	tmp = *src;
	while (tmp[i] != '\0' && tmp[i] != delim)
		i++;
	ret = ft_strnew(i);
	j = 0;
	while (j < i)
	{
		ret[j] = tmp[j];
		j++;
	}
	ret[j] = '\0';
	if (ft_strlen(*src) > j)
		*src = ft_strdup(&(tmp[j + 1]));
	else
		*src = NULL;
	ft_memdel((void**)&tmp);
	return (ret);
}

int			ft_strchr(char *src, char d)
{
	int		i;

	if (src == NULL)
		return (0);
	i = 0;
	while (src[i] != '\0' && src[i] != d)
		i++;
	if (src[i] == d)
		return (BOOL_TRUE);
	return (BOOL_FALSE);
}

int			ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}

int			ft_get_end_line(char *str)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*section;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(section = (char*)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len != 0)
	{
		section[i] = s[start + i];
		i++;
		len--;
	}
	section[i] = '\0';
	return (section);
}
