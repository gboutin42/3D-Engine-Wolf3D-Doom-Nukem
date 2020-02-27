/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboutin <gboutin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:42:56 by gboutin           #+#    #+#             */
/*   Updated: 2020/02/14 15:42:57 by gboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ft_size(long nb)
{
	int	size;

	size = 0;
	if (nb <= 0)
	{
		nb *= -1;
		size++;
	}
	while (nb > 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char	*array;
	int		size;
	long	nb;

	nb = n;
	size = ft_size(nb);
	if (!(array = (char*)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	array[size--] = '\0';
	if (nb == 0)
		array[0] = '0';
	if (nb < 0)
	{
		array[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		array[size] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
	return (array);
}
