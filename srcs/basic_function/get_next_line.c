/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:21:56 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int			get_errors(int fd, char **line)
{
	char	b[BUFF_SIZE + 1];

	if ((fd < 0 || read(fd, b, 0) < 0 || BUFF_SIZE <= 0 || line == NULL))
		return (1);
	return (0);
}

static char			*get_read(const int fd, char *str, char *buff)
{
	int		ret;

	if (str == NULL && (!(str = ft_strnew(0))))
		return (NULL);
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoinf(str, buff, 1);
	}
	ft_strdel(&buff);
	return (str);
}

static t_list_fd	*ft_check_fd(const int fd, t_list_fd **begin)
{
	t_list_fd	*tmp;
	t_list_fd	*new;

	tmp = *begin;
	new = NULL;
	while (tmp)
	{
		if ((int)tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = (t_list_fd*)ft_memalloc(sizeof(t_list_fd))))
		return (NULL);
	new->rest = NULL;
	new->fd = fd;
	ft_lstadd(begin, new);
	return (new);
}

static int			end_of_gnl(t_list_fd **begin)
{
	ft_lstdel(begin, &ft_del_cont);
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd	*begin = NULL;
	char				*tmp;
	char				*buff;
	int					endline;
	t_list_fd			*current;

	*line = NULL;
	if (get_errors(fd, line) == 1 || !(current = ft_check_fd(fd, &begin))
											|| !(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	current->rest = get_read(fd, (char*)current->rest, buff);
	if ((ft_strcmp(current->rest, "") == 0) && (read(fd, buff, BUFF_SIZE) == 0))
		return (end_of_gnl(&begin));
	else if ((char*)current->rest)
	{
		endline = ft_get_end_line((char*)current->rest);
		*line = ft_strsub((char*)current->rest, 0, endline);
		if (((char*)current->rest)[endline] == '\0')
			tmp = ft_strdup(((char*)current->rest) + endline);
		else
			tmp = ft_strdup(((char*)current->rest) + endline + 1);
		ft_strdel((char**)&current->rest);
		ft_strdel(&tmp);
	}
	return (1);
}
