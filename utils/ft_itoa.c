/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:23:37 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/02 19:23:51 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_size(int num)
{
	int	x;

	x = 0;
	while (num != 0)
	{
		x++;
		num /= 10;
	}
	return (x);
}

static char	*allocate(int size)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	return (ptr);
}

static char	*negative(long nb)
{
	int		size;
	char	*ptr;
	int		i;

	nb *= -1;
	size = ft_size(nb) + 1;
	ptr = allocate(size);
	if (!ptr)
		return (NULL);
	i = size;
	ptr[i--] = '\0';
	while (nb != 0)
	{
		ptr[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	ptr[i] = '-';
	return (ptr);
}

static char	*positive(long nb)
{
	int		size;
	char	*ptr;
	int		i;

	size = ft_size(nb);
	ptr = allocate(size);
	if (!ptr)
		return (NULL);
	i = size;
	ptr[i--] = '\0';
	while (nb != 0)
	{
		ptr[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ptr;

	nb = n;
	if (nb < 0)
	{
		ptr = negative(nb);
	}
	else if (nb > 0)
	{
		ptr = positive(nb);
	}
	else
	{
		ptr = allocate(1);
		ptr[0] = '0';
		ptr[1] = '\0';
	}
	if (!ptr)
		return (NULL);
	return (ptr);
}
