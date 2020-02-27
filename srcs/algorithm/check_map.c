/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:41:29 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/27 10:22:44 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_item2(char *s)
{
	if (ft_strcmp(s, "Ammo_Pack") == '_')
	{
		if (s[10] == '0')
			return (0);
		if ((is_number(&s[10])))
			return (1);
	}
	else if (ft_strcmp(s, "Health_Pack") == '_')
	{
		if (s[12] == '0')
			return (0);
		if ((is_number(&s[12])))
			return (1);
	}
	return (0);
}

int		check_item(char *s)
{
	if (ft_strcmp(s, "Card_red") == 0 || ft_strcmp(s, "Card_blue") == 0
										|| ft_strcmp(s, "Card_green") == 0)
		return (1);
	else if (ft_strcmp(s, "Jet_Pack") == '_')
	{
		if (s[9] == '0')
			return (0);
		if ((is_number(&s[9])))
			return (1);
	}
	else if (ft_strcmp(s, "Armor_Pack") == '_')
	{
		if (s[11] == '0')
			return (0);
		if ((is_number(&s[11])))
			return (1);
	}
	else
	{
		if (!(check_item2(s)))
			return (0);
		else
			return (1);
	}
	return (0);
}

int		check_mesh(char **s)
{
	if (ft_tablen(s) != 18)
	{
		if (ft_tablen(s) != 19)
			return (0);
		if (ft_tablen(s) == 19 && (s[18][0] != '*' && s[18][0] != '#'))
			return (0);
	}
	if (ft_strcmp(s[0], "item:") == 0)
		if (!(check_item(s[1])))
			return (0);
	return (1);
}

int		map_checker(char **s, int *idx)
{
	static int i = 0;

	i++;
	if (i >= 249)
		return (0);
	if (s[0][0] == '/' || s[0][0] == '*')
		return (1);
	if (ft_strcmp(s[0], "player:") == 0)
	{
		*idx = 1;
		if (ft_tablen(s) != 33)
			return (0);
		if (ft_strcmp(s[1], "Player") != 0)
			return (0);
	}
	else if (ft_strcmp(s[0], "cube:") == 0 || ft_strcmp(s[0], "plane:") == 0
						|| ft_strcmp(s[0], "item:") == 0 || s[0][0] == '#')
	{
		if (!(check_mesh(s)))
			return (0);
	}
	else
		return (0);
	return (1);
}

void	check_map(char *path)
{
	int		fd;
	int		idx;
	char	*line;
	char	**s;

	idx = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		error_exit(-7000, "impossible fd");
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != 0)
		{
			if (!(s = ft_strsplit(line, ' ')))
				error_exit(-1665, "error split");
			if (!(map_checker(s, &idx)))
				error_exit(30, "error in map");
			ft_freetab(&s);
		}
		ft_strdel(&line);
	}
	if (idx == 0)
		error_exit(-9998, "no player in map");
	ft_strdel(&line);
}
