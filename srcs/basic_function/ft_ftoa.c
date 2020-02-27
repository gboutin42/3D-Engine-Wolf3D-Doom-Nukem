/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:03:19 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 11:59:00 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	create_string(float nb, char *rest, int i, size_t precision)
{
	size_t	afterdots;
	int		dot;

	dot = 0;
	afterdots = 0;
	if (nb < 1)
	{
		rest[i++] = '.';
		dot = i;
		while (afterdots < precision)
		{
			nb *= 10;
			if (((int)(nb + 0.01)) != 10)
				rest[i++] = (int)(nb + 48 + 0.01);
			nb -= (int)nb;
			afterdots++;
		}
	}
	while (i - dot < 2)
		rest[i++] = '0';
	rest[i] = '\0';
}

char	*ft_ftoa_p(float n, size_t precision)
{
	char		*flt;
	char		*first;
	long int	nb;
	int			i;
	int			j;

	i = -1;
	j = -1;
	nb = (long int)n;
	first = ft_itoa(nb);
	flt = (char *)ft_memalloc(100);
	n -= (float)nb;
	if (n < 0)
	{
		n *= -1;
		if (nb == 0)
			flt[++j] = '-';
	}
	while (first[++i])
		flt[++j] = first[i];
	create_string(n, flt, i, precision);
	ft_memdel((void**)&first);
	return (flt);
}

char	*ft_ftoa(float n)
{
	char		*flt;
	char		*first;
	long int	nb;
	int			i;
	int			j;

	i = -1;
	j = -1;
	nb = (long int)n;
	first = ft_itoa(nb);
	flt = (char *)ft_memalloc(100);
	n -= (float)nb;
	if (n < 0)
	{
		n *= -1;
		if (nb == 0)
			flt[++j] = '-';
	}
	while (first[++i])
		flt[++j] = first[i];
	create_string(n, flt, i, 2);
	ft_memdel((void**)&first);
	return (flt);
}
