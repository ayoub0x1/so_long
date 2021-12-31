/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roudouch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 10:52:39 by roudouch          #+#    #+#             */
/*   Updated: 2021/12/12 10:52:43 by roudouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(t_vars ***v, char *err)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	printf("%s", err);
	exit(1);
}

static void	check_is_rectangular(t_vars **vars)
{
	int	y_map;
	int	x_map;
	int	height;
	int	backup;

	y_map = 0;
	backup = 0;
	height = get_height((*vars)->map);
	while (y_map != height)
	{
		x_map = 0;
		while ((*vars)->map[y_map][x_map] != '\0')
			x_map++;
		y_map++;
		if (backup != 0)
		{
			if (backup != x_map)
				ft_error(&vars,
					"\033[1;31m🛑ERROR: map is not rectangular\033[0m");
		}
		else
			backup = x_map;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_surrounded_by_walls(t_vars **v)
{
	int		i;
	char	*err;

	err = "\033[1;31m🛑ERROR: map is not surrounded by walls\033[0m";
	if (check_line((*v)->map[0]))
		ft_error(&v, err);
	i = get_height((*v)->map) - 1;
	while (i)
	{
		if ((*v)->map[i][0] != '1' ||
			(*v)->map[i][ft_strlen((*v)->map[i]) - 1] != '1')
		{
			ft_error(&v, err);
		}
		i--;
	}
	if (check_line((*v)->map[get_height((*v)->map) - 1]))
		ft_error(&v, err);
}

void	check_map_valid(t_vars *vars)
{
	check_is_rectangular(&vars);
	check_surrounded_by_walls(&vars);
	check_elements(&vars);
}
