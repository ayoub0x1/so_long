/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:21:58 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/02 19:22:15 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_err_message(t_map_vars *map)
{
	if (map->c == 0)
		return (
			"\033[1;31m🛑ERROR: element 'C' is missing\033[0m");
	if (map->p == 0)
		return (
			"\033[1;31m🛑ERROR: element 'P' is missing\033[0m");
	if (map->e == 0)
		return (
			"\033[1;31m🛑ERROR: element 'E' is missing\033[0m");
	if (map->p == 0)
		return (
			"\033[1;31m🛑ERROR: element 'P' is missing\033[0m");
	if (map->p > 1)
		return (
			"\033[1;31m🛑ERROR: there is more then one element 'P'\033[0m");
	return ("\033[1;31m🛑ERROR: element missing in the map\033[0m");
}

char	*unknown_element(t_vars ***v, char c)
{
	int	x;

	x = 0;
	while ((**v)->map[x])
	{
		free((**v)->map[x]);
		x++;
	}
	free((**v)->map);
	printf("\033[1;31m🛑ERROR: Unknown element %c \033[0m", c);
	exit(1);
}

void	check_elements(t_vars **vars)
{
	t_map_vars	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height((*vars)->map) - 1;
	while (map.y--)
	{
		map.x = 0;
		while ((*vars)->map[map.y][map.x] != '\0')
		{
			if ((*vars)->map[map.y][map.x] == 'E')
				map.e++;
			else if ((*vars)->map[map.y][map.x] == 'P')
				map.p++;
			else if ((*vars)->map[map.y][map.x] == 'C')
				map.c++;
			else if ((*vars)->map[map.y][map.x] != '1' &&
				(*vars)->map[map.y][map.x] != '0')
				unknown_element(&vars, (*vars)->map[map.y][map.x]);
			map.x++;
		}
	}
	if (map.c == 0 || map.p == 0 || map.e == 0 || map.p > 1)
		ft_error(&vars, ft_err_message(&map));
}
