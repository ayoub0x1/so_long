/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymoulou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:14:24 by aymoulou          #+#    #+#             */
/*   Updated: 2022/01/02 19:14:35 by aymoulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check(t_vars ***vars, int x, int y)
{
	if ((**vars)->map[y][x] == '0' && (**vars)->map[y][x + 1] == '0'
		&& (**vars)->map[y][x + 2] == '0')
	{
		(**vars)->e_vars.sign = 0;
		(**vars)->e_vars.x_e = x;
		(**vars)->e_vars.y_e = y;
		return (1);
	}
	return (0);
}

int	get_position_for_enemy(t_vars **vars)
{
	int			y;
	int			x;
	int			height;

	y = 0;
	height = get_height((*vars)->map);
	if ((*vars)->e_vars.sign)
	{
		while (y != height)
		{
			x = 0;
			while ((*vars)->map[y][x] != '\0')
			{
				if (check(&vars, x, y))
					return (1);
				x++;
			}
			y++;
		}
		return (0);
	}
	return (1);
}

void	open_exit(t_vars **vars)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*vars)->map);
	while (y != height)
	{
		x = 0;
		while ((*vars)->map[y][x] != '\0')
		{
			if ((*vars)->map[y][x] == 'E')
			{
				(*vars)->img = mlx_xpm_file_to_image(
						(*vars)->mlx, "./img/o_exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window(
					(*vars)->mlx, (*vars)->win, (*vars)->img, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
